#include<iostream>
#define SIZE 13
int dp[SIZE];
int main(void) {
	int N;scanf("%d", &N);

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);

		for (int i = 4; i <= 11; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		printf("%d\n", dp[num]);
	}

}