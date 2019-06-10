#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct Node{
	int y;
	int x;
};

int main() {

	string s;
	int tc;

	bool visit[100][100] = { false, };
	int maze[100][100];
	int dir[4][2] = { {0.1},{1,0},{0,-1},{-1,0} };

	int i, j;
	for (tc = 1; tc <= 10; tc++) {

		int start_x = 0, start_y = 0;
		int end_x = 0, end_y = 0;
		int result = 0;

		for (i = 0; i < 100; i++) {
			cin >> s;
			for (j = 0; j < 100; j++) {
				maze[i][j] = s[j] - '0';
				if (maze[i][j] == 2) {
					start_x = j;
					start_y = i;
				}
				if (maze[i][j] == 3) {
					end_x = j;
					end_y = i;
				}
			}
		}

		stack<Node> s;
		visit[start_y][start_x] = true;
		s.push({ start_y,start_x });

		while (!s.empty()) {

			Node n = s.top();
			s.pop();

			if (n.x == end_x && n.y == end_y) {
				result = 1;
				break;
			}
			for (i = 0; i < 4; i++) {
				int x = n.x + dir[i][0];
				int y = n.y + dir[i][1];

				if (x >= 0 && x < 100 && y>=0 && y < 100){
					if (maze[y][x] != 1 && !visit[y][x]) {
						visit[y][x] = true;
						s.push({ y,x });
					}
				}
			}
		}
		cout << "#" << tc << " " << result << endl;
	}
	return 0;
}