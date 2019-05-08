#include<iostream>
#include<string>
#include<stack>
using namespace std;


struct Node {
	int y;
	int x;
};
int main() {


	int i,j,tc,t;
	
	int map[100][100];
	bool visited[100][100] = { false, };

	// 오른쪽 왼쪽 아래 순서로
	int dir[3][2] = { {0,1},{0,-1},{-1,0} };
	

	for (tc = 0; tc < 10; tc++) {
		
		int result = 0;
		int end_y = 0, end_x = 0;
		cin >> t;

		//사디리 맵 받기
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				cin >> map[i][j];
				
				if (map[i][j] == 2) {
					end_x = j;
					end_y = i;
				}
			}
		}

		// 스택 
		stack<Node> s;
		visited[end_y][end_x] = true;
		s.push({end_y,end_x});

		//dfs
		while (!s.empty()) {
					
			Node n = s.top();
			s.pop();	

			int cur_y = n.y;
			int cur_x = n.x;

			if (cur_y == 0) {
				result = cur_x;
				break;
			}

			for (i = 0; i < 3; i++) {
				int y = cur_y + dir[i][0];
				int x = cur_x + dir[i][1];

				if (y >= 0 && y < 100 && x >= 0 && x < 100) {
					if (map[y][x] == 1 && visited[y][x] == false) {
						visited[y][x] = true; 
						s.push({ y,x });
					}
				}
			}
		}		
		cout << "#" << t << " " << result << endl;
	}
	return 0;
}