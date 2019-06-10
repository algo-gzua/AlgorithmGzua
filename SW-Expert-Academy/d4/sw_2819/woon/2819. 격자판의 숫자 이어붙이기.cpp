#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// 맵크기 설정
int map[4][4];

// 방향 위 오른쪽 아래 왼쪽
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
		//맵 그리기
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		int count = 0;
		string s = "";

		//모든 dfs 경우
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				dfs(i, j, count, s);
			}
		}

		//dfs 끝나고 중복된 수 지우기

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int check = v.size();

		cout << "#" << tc + 1 << " " << check;
	}



	return 0;
}