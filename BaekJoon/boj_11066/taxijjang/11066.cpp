#include<iostream>
#include<algorithm>
#define SIZE 510
#define INF 2e9
using namespace std;

int arr[SIZE], dp[SIZE][SIZE] , p_sum[SIZE];
int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		int N;scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			p_sum[i] = p_sum[i - 1] + arr[i];
		}

		for (int len = 2; len <= N; len++) {
			printf("len : %d \n", len);
			for (int i = 1; i <= N - len + 1; i++) {
				int j = i + len - 1;
				dp[i][j] = INF;
				for (int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p_sum[j] - p_sum[i - 1]);
					printf("%d %d %d\n", i, k, j);
					//dp[i][j] += p_sum[j] - p_sum[i - 1];
				}
			}
		}
		printf("%d\n", dp[1][N]);
	}
}