#include<iostream>
#include<queue>
#include<algorithm>

#define MAX 102
#define INF 999999999
using namespace std;

int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

int sum[MAX][MAX];
int arr[MAX][MAX];

void bfs(int h_x, int h_y, int N) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(h_x, h_y));
	sum[1][1] = 0;
	while (!q.empty()) {
		h_x = q.front().first;
		h_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];

			if (n_x > 0 && n_x <= N && n_y > 0 && n_y <= N) {
				if (sum[n_x][n_y]  > sum[h_x][h_y] + arr[n_x][n_y]) {
					sum[n_x][n_y] = sum[h_x][h_y] + arr[n_x][n_y];
					q.push(pair<int, int>(n_x,n_y));
				}
			}
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		fill(&sum[0][0], &sum[MAX][MAX], INF);
		fill(&arr[0][0], &arr[MAX][MAX], 0);

		sum[1][1] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}

		bfs(1, 1, N);

		printf("#%d %d\n", t, sum[N][N]);
	}
}