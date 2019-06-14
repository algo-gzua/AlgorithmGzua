#include<iostream>
#include<algorithm>

using namespace std;

#define SIZE 1001
int RGB[3][SIZE];
int dp[3][SIZE];

int main(void) {
	int N; scanf("%d", &N);
	
	int R = 0, G = 1, B = 2;

	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &RGB[R][i],&RGB[G][i],&RGB[B][i]);

	dp[R][0] = RGB[R][0]; dp[G][0] = RGB[G][0]; dp[B][0] = RGB[B][0];
	for (int i = 1; i < N; i++) {
		dp[R][i] = min(dp[G][i - 1], dp[B][i - 1]) + RGB[R][i];
		dp[G][i] = min(dp[R][i - 1], dp[B][i - 1]) + RGB[G][i];
		dp[B][i] = min(dp[R][i - 1], dp[G][i - 1]) + RGB[B][i];
	}

	printf("%d\n", min(min(dp[R][N - 1], dp[G][N - 1]), dp[B][N - 1]));
}