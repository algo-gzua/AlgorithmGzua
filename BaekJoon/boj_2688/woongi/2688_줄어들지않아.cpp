#include <iostream>
using namespace std;

long long dp[10][65];

void init() {
	// 테투리 채우기
	for (int i = 2; i <= 64; i++) {
		dp[0][i] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		dp[i][2] = i + 1;
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 3; j <= 64; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
}

int main() {

	int t, tc;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		init();

		int n;
		cin >> n;

		long long sum = 0;

		if (n == 1) {
			sum = 10;
		}
		else {
			for (int j = 0; j <= 9; j++) {
				sum = sum + dp[j][n];
			}
		}
		

		cout << sum << endl;
	}
	return 0;
}