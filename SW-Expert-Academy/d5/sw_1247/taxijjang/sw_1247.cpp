#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int INF = 999999999;
bool visited[15];
int arr[15][2];

int dfs_sum = INF;

void dfs(int h_x, int h_y, int len, int N, int C) {
	if (N == C) {
		dfs_sum = min(dfs_sum, len + abs(h_x - arr[1][0]) + abs(h_y - arr[1][1]));
		return;
	}
	for (int i = 2; i < N + 2; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			dfs(arr[i][0], arr[i][1], len + abs(h_x - arr[i][0]) + abs(h_y - arr[i][1]), N, C + 1);
			visited[i] = false;
		}
	}
}
int main(void) {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N; scanf("%d", &N);

		for (int i = 0; i < N + 2; i++) {
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		}

		dfs(arr[0][0], arr[0][1], 0, N, 0);

		printf("#%d %d\n", t, dfs_sum);
		fill(visited, visited + 15, false);
		fill(&arr[0][0], &arr[15][0], 0);
		dfs_sum = INF;
	}
}