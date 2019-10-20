#include <iostream>
#include <queue>
using namespace std;

typedef struct NODE {
	int x;
	int y;
}node;

int map[300][300];
int water[300][300];
bool visited[300][300];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };


int bfs(int i, int j, int n, int m) {

	queue<node> q;
	int start_x = i, start_y = j;
	
	q.push({ start_x,start_y });
	visited[start_x][start_y];

	int result = 0;
	while (!q.empty()) {

		node q1 = q.front();
		q.pop();

		for (int a = 0; a < 4; a++) {
			int x = q1.x + dir_x[a];
			int y = q1.y + dir_y[a];

			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (map[x][y] > 0) {
					if (visited[x][y] == false) {
						visited[x][y] = true;
						q.push({ x,y });
						result = result + 1;
					}
				}
			}
		}
	}
	return result;
}

int check(int i, int j) {

	int count = 0;

	//위 오른쪽 아래 왼쪽
	if (map[i - 1][j] <= 0) {
		count++;
	}
	if (map[i][j + 1] <= 0) {
		count++;
	}
	if (map[i + 1][j] <= 0) {
		count++;
	}
	if (map[i][j - 1] <= 0) {
		count++;
	}

	return count;
}


int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	bool flag = true;
	int tmp = 0;
	while (true) {

		// 몇개의 빙산이 있는지 체크
		int plus = 0;
		int start_x = -1;
		int start_y = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0) {
					plus = plus + 1;

					if (start_x == -1 && start_y == -1) {
						start_x = i;
						start_y = j;
					}
				}
			}
		}
		
		if (plus == 0 || plus == 1) {
			tmp = 0;
			break;
		}

		//큐를 이용해서 몇개가 연결됬는지 확인
		//plus 랑 같으면 연결된 상태
		int point = bfs(start_x, start_y, n, m);
		if (point != plus) {
			flag = false;
		}

		if (flag == false) {
			break;
		}

		//인접한 물 갯수 확인하기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0) {
					water[i][j] = check(i, j);
				}
			}
		}

		//1년갱신
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] <= 0) {
					continue;
				}
				map[i][j] = map[i][j] - water[i][j];
			}
		}

		tmp++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
	}


	cout << tmp;
	return 0;
}