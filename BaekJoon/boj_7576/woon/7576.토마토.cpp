#include<iostream>
#include<string>
#include<queue>
using namespace std;


struct Node {
	int x;
	int y;
	int count;
};

// ���������� ���� 
// ���������� stack������ ���������� hip�� ����
int box[1000][1000];
bool visited[1000][1000];


int main() {

	int i, j, n, m;

	//�� ������ �Ʒ� ����
	int dir_x[4] = { -1,0,1,0 };
	int dir_y[4] = { 0,1,0,-1 };

	Node node;
	queue<Node> q;

	cin >> n >> m;
	// box����� visited �迭 �����
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
	//�������� �ΰ��̻��� ��� ����ü �ȿ� turn ������ �ϳ��ּ� �߰���Ű��
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
				// �湮�� �����ʾ�����
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

	// �� ���ʹ� ��� return -1 ���
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (box[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	//�� �ʹ� ��� day ���
	cout << node.count << endl;


	/*for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << box[i][j];
		}
		cout << endl;
	}*/


	return 0;
}