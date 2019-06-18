#include<iostream>
#include<string>
#include<queue>
using namespace std;


struct Node {
	int x;
	int y;
	int count;
};

// 전역변수로 선언 
// 지역변수는 stack에저장 전역변수는 hip에 저장
int box[1000][1000];
bool visited[1000][1000];


int main() {

	int i, j, n, m;

	//위 오른쪽 아래 왼쪽
	int dir_x[4] = { -1,0,1,0 };
	int dir_y[4] = { 0,1,0,-1 };

	Node node;
	queue<Node> q;

	cin >> n >> m;
	// box만들고 visited 배열 만들기
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				visited[i][j] = true;
				node.x = i;
				node.y = j;
				q.push({ node.x,node.y, 0 });
			}
			if (box[i][j] == -1) {
				visited[i][j] = true;
			}
		}
	}


	int day = 0;
	//시작점이 두개이상일 경우 구조체 안에 turn 변수를 하나둬서 추가시키기
	while (!q.empty()) {

		node.x = q.front().x;
		node.y = q.front().y;
		node.count = q.front().count;

		q.pop();

		for (i = 0; i < 4; i++) {
			int next_x = node.x + dir_x[i];
			int next_y = node.y + dir_y[i];

			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !visited[next_x][next_y]) {
				box[next_x][next_y] = 1;
				// 방문을 하지않았을때
				q.push({ next_x,next_y,node.count + 1 });
				visited[next_x][next_y] = true;

				/*for (i = 0; i < m; i++) {
					for (j = 0; j < n; j++) {
						cout << box[i][j];
					}
					cout << endl;
				}*/
			}
		}
	}

	// 다 못익는 경우 return -1 출력
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (box[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	//다 익는 경우 day 출력
	cout << node.count << endl;


	/*for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << box[i][j];
		}
		cout << endl;
	}*/


	return 0;
}