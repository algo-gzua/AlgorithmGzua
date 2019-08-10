#include<iostream>
#include<algorithm>
#define SIZE 560
#define INF 2e9

using namespace std;

int arr[SIZE];
int dp[SIZE][SIZE];
int main(void) {
	int N; scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d %d", &arr[n], &arr[n + 1]);
	}

	/*for (int i = 1; i <= N-1; i++) {
		dp[i][i + 1] = arr[i].first*arr[i].second*arr[i + 1].second;
	}*/

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i-1]*arr[k]*arr[j]);
			}
		}
	}
	printf("%d\n", dp[1][N]);
};