#include <iostream>
#include <string>
#include <stack>
#include <vector> 

using namespace std;

//map 
int map[100][100];
bool visited[100][100];
// 위 오른쪽 아래 왼쪽
int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };


// 가로 세로 넓이
struct Node {

	int w;
	int h;
	int area;
};

//정보 담는 스택
stack<Node> st;

//임시저장소
stack<Node> st1;

void compare(stack<Node> &st){ 

	//담아줄 노드 만들기
	Node p1;
	Node p2;
	Node p3;

	// st 스택에 있는 수를 뺴서 담아줌
	p1 = st.top();
	st.pop();

	p2 = st.top();
	st.pop();

	// 두수를 비교
	// 넓이 p1 < p2
	if (p1.area < p2.area) {
		if (st.empty()) {
			//작은건 다른 스택에 담고
			st1.push(p1);

			//큰놈은 기존의 스택에 담기
			st.push(p2);
			while (!st1.empty()) {
				p3 = st1.top();
				st1.pop();
				st.push(p3);
			}
		}
		else {
			st1.push(p1);
			st.push(p2);
			compare(st);
		}
	}
	//크기가 같으면
	else if (p1.area == p2.area) {
	
		// 행이 작은걸 우선으로(p1 < p2)
		if (p1.w < p2.w) {
			
			//크기가 같고 비어있을때
			if (st.empty()) {

				//작은건 다른 스택에 담고
				st1.push(p1);

				//큰놈은 기존의 스택에 담기
				st.push(p2);
				while (!st1.empty()) {
					p3 = st1.top();
					st1.pop();
					st.push(p3);
				}
			}
			else {
				// 비어있지않다면 
				// 작은놈은 새로운곳에
				st1.push(p1);

				//큰놈은 원래곳에
				st.push(p2);
				
				//비교문 다시 돌리기
				compare(st);
			}
		}
		// p1 > p2
		else if (p1.w > p2.w) {
			if (st.empty()) {
				//작은건 다른 스택에 담고
				st1.push(p2);

				//큰놈은 기존의 스택에 담기
				st.push(p1);

				//임시저장소 스택이 빌때까지
				while (!st1.empty()) {
					p3 = st1.top();
					st1.pop();
					st.push(p3);
				}
			}
			else {
				// 비어있지않다면 
				// 작은놈은 새로운곳에
				st1.push(p2);

				//큰놈은 원래곳에
				st.push(p1);

				//비교문 다시 돌리기
				compare(st);
			}
		}
	}
	// 넓이 p1 > p2
	else if (p1.area > p2.area) {
		if (st.empty()) {
			//작은건 다른 스택에 담고
			st1.push(p2);

			//큰놈은 기존의 스택에 담기
			st.push(p1);
			while (!st1.empty()) {
				p3 = st1.top();
				st1.pop();
				st.push(p3);
			}
		}
		else {
			// 비어있지않다면 
			// 작은놈은 새로운곳에
			st1.push(p2);

			//큰놈은 원래곳에
			st.push(p1);

			//비교문 다시 돌리기
			compare(st);
		}
	}
}

void check(int x, int y, int area) {

	// 스택이 비어있다면 스택에 넣어주기
	if (st.empty()) {
		st.push({ x,y,area });
	}
	else {
		// 비어있지않다면 비교
		st.push({ x,y,area });
		compare(st);
	}
}

void search(int start_x, int start_y, int n) {

	// 위치의 값이 0이 아닐때의 좌표를 시작점으로 둠
	// 모양은 사각형이기 때문에 x축만 키우거나 y축만 키우기
	
	//x축만 키우기(열)
	int row = 0;
	int n_y = start_y;
	while (map[start_x][n_y] != 0) {
		n_y++;
		row++;
	}

	//y축만 키우기(행)
	int col = 0;
	int n_x = start_x;
	while (map[n_x][start_y] != 0) {
		n_x++;
		col++;
	}
	
	//범위만큼 방문체크
	for (int i = start_x; i < n_x; i++) {
		for (int j = start_y; j < n_y; j++) {
			visited[i][j] = true;
		}
	}


	int area = 0;
	area = (col * row);

	// 행,열,넓이
	check(col, row, area);
	
}

int main() {

	int i, j, n;
	int tc, t;

	cin >> t;
	for (tc = 0; tc < t; tc++) {
		cin >> n;

		// 맵 초기화
		fill(&map[0][0], &map[n][n], 0);
		// 방문 초기화
		fill(&visited[0][0], &visited[n][n], false);

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		//탐색 0이 나올때까지
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][j] != 0 && visited[i][j] == false) {
					// 상자의 크기 찾기
					search(i, j, n);
				}
			}
		}

		vector<Node> v;
		vector<Node>::iterator iter = v.begin();

		int size = st.size();
		for (i = 0; i < size; i++) {
			v.push_back(st.top());
			st.pop();
		}

		cout <<"#"<<tc+1<<" "<< size << " ";
		for (iter = v.begin(); iter != v.end(); iter++) {
			cout << iter->w << " " << iter->h << " ";
		}

		// stack 초기화
		while (!st.empty()) {
			st.pop();
		}
		// vector 초기화
		vector<Node>().swap(v);
	}	
	return 0;
}