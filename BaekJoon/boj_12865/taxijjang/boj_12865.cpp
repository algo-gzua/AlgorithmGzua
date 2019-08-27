#include<iostream>
#include<algorithm>
#define SIZE 100010


using namespace std;

int dp[110][SIZE];

int main(void) {
	ios::sync_with_stdio(false);

	int N, K; cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int w, c; cin >> w >> c;
		for (int j = 1; j <= K; j++) {
			if (j - w >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + c);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}