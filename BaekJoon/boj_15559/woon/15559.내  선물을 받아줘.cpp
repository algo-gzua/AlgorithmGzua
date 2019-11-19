#include <iostream>
using namespace std;

char map[1001][1001];
int result[1001][1001];
bool visited[1001][1001];

int now;
int min_count;
void create_map(int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

}

void dfs(int x, int y, int n, int m) {

	visited[x][y] = true;
	result[x][y] = now;
	int n_x = x;
	int n_y = y;

	// µ¿¼­³²ºÏ
	if (map[x][y] == 'N') {
		n_x = x - 1;
	}
	else if (map[x][y] == 'E') {
		n_y = y + 1;
	}
	else if (map[x][y] == 'S') {
		n_x = x + 1;
	}
	else {
		n_y = y - 1;
	}

	if (visited[n_x][n_y] == false) {
		result[n_x][n_y] = now;
		dfs(n_x, n_y, n, m);
	}
	else if (visited[n_x][n_y] == true && now == result[n_x][n_y]) {
		min_count++;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	create_map(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false) {
				dfs(i, j, n, m);
				now++;
			}
		}
	}

	cout << min_count;
	return 0;
}