#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define SIZE 301

using namespace std;

int arr[SIZE][SIZE];
int m[SIZE][SIZE];
bool visited[SIZE][SIZE];


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

void dfs(int h_x, int h_y) {
	visited[h_x][h_y] = true;

	for (int i = 0; i < N; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];
		if (n_x >=0 && n_x < N && n_y >=0  && n_y < M) {
			if (arr[n_x][n_y] == 0)
				m[h_x][h_y]++;

			if (visited[n_x][n_y] == false && arr[n_x][n_y] != 0)
				dfs(n_x, n_y);
		}
	}
}


void fill() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			m[i][j] = 0;
		}
	}
}
void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = arr[i][j] - m[i][j] < 0 ? 0 : arr[i][j] - m[i][j];
		}
	}


}
void init() {
	int year = 0;
	while (1) {
		int group_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] != true && arr[i][j] != 0) {
					dfs(i, j);
					group_cnt++;
				}
			}
		}

		if (group_cnt == 0) {
			cout << '0';
			break;
		}
		else if (group_cnt >= 2) {
			cout << year;
			break;
		}
		melt();
		fill();
		year++;
	}

}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	init();

	return 0;
}