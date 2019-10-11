#include<iostream>
#define SIZE 510
using namespace std;

int arr[SIZE][SIZE];
int dp[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int dfs(int h_x, int h_y) {
	if (h_x == N && h_y == M)
		return dp[h_x][h_y] = 1;
	
	dp[h_x][h_y] = 0;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (n_x < 1 || n_y < 1 || n_x > N || n_y > M)
			continue;
		if (arr[h_x][h_y] <= arr[n_x][n_y])
			continue;
		
		if (dp[n_x][n_y] != -1) {
			dp[h_x][h_y] += dp[n_x][n_y];
			continue;
		}
		dp[h_x][h_y] += dfs(n_x, n_y);
	}
	return dp[h_x][h_y];

}

void fill_dp() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = -1;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	 cin >> N >> M;

	fill_dp();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 1);
}