#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


struct NODE {
	int x;
	int y;
	int count;
};

int r, c;
int map[51][51];
bool visited[51][51];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

void init(int r, int c) {

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j]-'0';
			if (map[i][j] == 28) {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
}
int bfs(int x, int y) {

	int high = 0;
	queue<NODE> q;
	fill(&visited[0][0], &visited[51][51], false);

	q.push({ x,y,0 });
	visited[x][y] = true;


	NODE node;
	while (!q.empty()) {

		node.x = q.front().x;
		node.y = q.front().y;
		node.count = q.front().count;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int n_x = node.x + dir_x[i];
			int n_y = node.y + dir_y[i];

			//맵 안에 있을때
			if (n_x >= 0 && n_x < r && n_y >= 0 && n_y < c) {
				if (!visited[n_x][n_y] && map[n_x][n_y] == 1) {
					q.push({ n_x,n_y,node.count + 1 });
					visited[n_x][n_y] = true;
				}
			}
		}
	}
	
	
	high = node.count;
	return high;
}

int main() {

	cin >> r >> c;

	init(r, c);

	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				result = max(result, bfs(i, j));
			}
		}
	}

	cout << result;

	return 0;
}