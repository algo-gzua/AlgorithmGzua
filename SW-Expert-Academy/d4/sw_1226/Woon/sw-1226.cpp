#include<iostream>
#include<string>
#include<stack>

using namespace std;


struct point {
	int y;
	int x;
};

int main() {

	int i, j;
	int maze[16][16];
	bool visited[16][16];
	int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int t;

	for (t = 1; t <= 10; t++) {

		int start_x=0, start_y = 0;
		int end_x=0, end_y = 0;
		int tc;
		int result = 0;
		fill(&visited[0][0], &visited[15][15], false);

		cin >> tc;
		// 미로판 그리기
		for (i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (j = 0; j < 16; j++) {
				maze[i][j] = s[j] - '0';
			}

			if (maze[i][j] == 2) {
				start_x = j;
				start_y = i;
			}
			if (maze[i][j] == 3) {
				end_x = j;
				end_y = i;
			}
		}
		stack<point> s;
		visited[start_y][start_x] = true;
		s.push({ start_y, start_x });

		//dfs 함수 작성
		while (!s.empty()) {
			point n = s.top();
			s.pop();
			if (n.x == end_x && n.y == end_y) {
				result = 1;
				break;
			}
			for (i = 0; i < 4; i++) {
				int x = n.x + dir[i][0];
				int y = n.y + dir[i][1];

				if (x >= 0 && x < 16 && y >= 0 && y < 16) {
					if (maze[y][x] != 1 && !visited[y][x]) {
						visited[y][x] = true;
						s.push({ y,x });
					}
				}
			}
		}
		cout << "#" << tc << " " << result << endl;
	}
	return 0;
}