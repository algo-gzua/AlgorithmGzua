#include<iostream>
#define SIZE 100010

const int mod = 9901;
int dp[SIZE][3];

int main(void) {
	int N; scanf("%d", &N);

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%mod;
	}

	printf("%d", (dp[N][0] + dp[N][1] + dp[N][2])%mod);

	return 0;
}