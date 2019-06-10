#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define inf 99999
using namespace std;


struct Node {
	int y;
	int x;
};


int main() {

	int i, j, n, tc, t;
	// �� ������ �Ʒ� ����
	int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	
	vector<vector<int> > v;
	vector<int> v_r;

	vector<vector<int> > result;
	vector<int> result_r;



	cin >> t;
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &n);

		//n,n vector �迭 �����
		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (j = 0; j < n; j++) {
				v_r.push_back(s[j] - '0');
			}
			v.push_back(v_r);
			// v_r �迭�� ��� ��
			for (j = 0; j < n; j++) {
				v_r.pop_back();
			}
		}

		// result �迭 �����
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				result_r.push_back(inf);
			}
			result.push_back(result_r);

			for (j = 0; j < n; j++) {
				result_r.pop_back();
			}
		}

		//queue �����
		queue<Node> q;
		Node node;


		//������ ť�� �־��ֱ�
		int start_y = 0, start_x = 0;
		int end_y = n, end_x = n;

		node.y = start_y;
		node.x = start_x;

		q.push(node);
		result[start_y][start_x] = 0;
		// bfs
		while (!q.empty()) {
			
			node.y = q.front().y;
			node.x = q.front().x;
			q.pop();


			for (i = 0; i < 4; i++) {
				int next_y = node.y + dir[i][0];
				int next_x = node.x + dir[i][1];

				if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < n) {
					if (result[next_y][next_x] > result[node.y][node.x] + v[next_y][next_x]) {
						result[next_y][next_x] = result[node.y][node.x] + v[next_y][next_x];
						q.push({ next_y,next_x });
					}
				}
			}


		}

		v.clear();
		result.clear();

		// vector �迭 �ʱ�ȭ

		// ���޷� ����
		/*for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}*/

		// ����� ���� �����ϴ� �迭 
		/*for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}*/

		cout << "#" << tc+1 <<" "<<result[n - 1][n - 1];

	}
	return 0;
}