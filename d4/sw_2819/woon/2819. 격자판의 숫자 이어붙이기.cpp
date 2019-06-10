#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// ��ũ�� ����
int map[4][4];

// ���� �� ������ �Ʒ� ����
int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };
vector<int> v;

struct Node {
	int x;
	int y;
};

void dfs(int x, int y, int count, string s) {
	stack<Node> st;

	int start_x = x;
	int start_y = y;

	st.push({ start_x,start_y });

	while (!st.empty()) {

		Node n;
		n = st.top();

		st.pop();
		count++;
		s = s + to_string(map[n.x][n.y]);

		if (count == 7) {
			v.push_back(stoi(s));
			return;
		}

		for (int i = 0; i < 4; i++) {

			int next_x = n.x + dir_x[i];
			int next_y = n.y + dir_y[i];

			if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4) {
				dfs(next_x, next_y, count, s);
			}
		}
	}
}
int main() {

	int i, j;
	int tc, t;

	cin >> t;
	for (tc = 0; tc < t; tc++) {
		//�� �׸���
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		int count = 0;
		string s = "";

		//��� dfs ���
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				dfs(i, j, count, s);
			}
		}

		//dfs ������ �ߺ��� �� �����

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int check = v.size();

		cout << "#" << tc + 1 << " " << check;
	}



	return 0;
}