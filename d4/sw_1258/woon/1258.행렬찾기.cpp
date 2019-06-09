#include <iostream>
#include <string>
#include <stack>
#include <vector> 

using namespace std;

//map 
int map[100][100];
bool visited[100][100];
// �� ������ �Ʒ� ����
int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };


// ���� ���� ����
struct Node {

	int w;
	int h;
	int area;
};

//���� ��� ����
stack<Node> st;

//�ӽ������
stack<Node> st1;

void compare(stack<Node> &st){ 

	//����� ��� �����
	Node p1;
	Node p2;
	Node p3;

	// st ���ÿ� �ִ� ���� ���� �����
	p1 = st.top();
	st.pop();

	p2 = st.top();
	st.pop();

	// �μ��� ��
	// ���� p1 < p2
	if (p1.area < p2.area) {
		if (st.empty()) {
			//������ �ٸ� ���ÿ� ���
			st1.push(p1);

			//ū���� ������ ���ÿ� ���
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
	//ũ�Ⱑ ������
	else if (p1.area == p2.area) {
	
		// ���� ������ �켱����(p1 < p2)
		if (p1.w < p2.w) {
			
			//ũ�Ⱑ ���� ���������
			if (st.empty()) {

				//������ �ٸ� ���ÿ� ���
				st1.push(p1);

				//ū���� ������ ���ÿ� ���
				st.push(p2);
				while (!st1.empty()) {
					p3 = st1.top();
					st1.pop();
					st.push(p3);
				}
			}
			else {
				// ��������ʴٸ� 
				// �������� ���ο����
				st1.push(p1);

				//ū���� ��������
				st.push(p2);
				
				//�񱳹� �ٽ� ������
				compare(st);
			}
		}
		// p1 > p2
		else if (p1.w > p2.w) {
			if (st.empty()) {
				//������ �ٸ� ���ÿ� ���
				st1.push(p2);

				//ū���� ������ ���ÿ� ���
				st.push(p1);

				//�ӽ������ ������ ��������
				while (!st1.empty()) {
					p3 = st1.top();
					st1.pop();
					st.push(p3);
				}
			}
			else {
				// ��������ʴٸ� 
				// �������� ���ο����
				st1.push(p2);

				//ū���� ��������
				st.push(p1);

				//�񱳹� �ٽ� ������
				compare(st);
			}
		}
	}
	// ���� p1 > p2
	else if (p1.area > p2.area) {
		if (st.empty()) {
			//������ �ٸ� ���ÿ� ���
			st1.push(p2);

			//ū���� ������ ���ÿ� ���
			st.push(p1);
			while (!st1.empty()) {
				p3 = st1.top();
				st1.pop();
				st.push(p3);
			}
		}
		else {
			// ��������ʴٸ� 
			// �������� ���ο����
			st1.push(p2);

			//ū���� ��������
			st.push(p1);

			//�񱳹� �ٽ� ������
			compare(st);
		}
	}
}

void check(int x, int y, int area) {

	// ������ ����ִٸ� ���ÿ� �־��ֱ�
	if (st.empty()) {
		st.push({ x,y,area });
	}
	else {
		// ��������ʴٸ� ��
		st.push({ x,y,area });
		compare(st);
	}
}

void search(int start_x, int start_y, int n) {

	// ��ġ�� ���� 0�� �ƴҶ��� ��ǥ�� ���������� ��
	// ����� �簢���̱� ������ x�ุ Ű��ų� y�ุ Ű���
	
	//x�ุ Ű���(��)
	int row = 0;
	int n_y = start_y;
	while (map[start_x][n_y] != 0) {
		n_y++;
		row++;
	}

	//y�ุ Ű���(��)
	int col = 0;
	int n_x = start_x;
	while (map[n_x][start_y] != 0) {
		n_x++;
		col++;
	}
	
	//������ŭ �湮üũ
	for (int i = start_x; i < n_x; i++) {
		for (int j = start_y; j < n_y; j++) {
			visited[i][j] = true;
		}
	}


	int area = 0;
	area = (col * row);

	// ��,��,����
	check(col, row, area);
	
}

int main() {

	int i, j, n;
	int tc, t;

	cin >> t;
	for (tc = 0; tc < t; tc++) {
		cin >> n;

		// �� �ʱ�ȭ
		fill(&map[0][0], &map[n][n], 0);
		// �湮 �ʱ�ȭ
		fill(&visited[0][0], &visited[n][n], false);

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		//Ž�� 0�� ���ö�����
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][j] != 0 && visited[i][j] == false) {
					// ������ ũ�� ã��
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

		// stack �ʱ�ȭ
		while (!st.empty()) {
			st.pop();
		}
		// vector �ʱ�ȭ
		vector<Node>().swap(v);
	}	
	return 0;
}