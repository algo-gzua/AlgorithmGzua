#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define SIZE 1010
using namespace std;

int arr[SIZE];
int dp[2][SIZE][35];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T, W; cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W+1; j++) {
			if (arr[i] == 1) {
				dp[0][i][j] = max(dp[0][i][j],max(dp[0][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1));
				dp[1][i][j] = max(dp[1][i][j],max(dp[0][i - 1][j - 1], dp[1][i - 1][j]));
			}
			else {
				dp[0][i][j] = max(dp[0][i][j],max(dp[0][i - 1][j], dp[1][i - 1][j - 1]));
				dp[1][i][j] = max(dp[1][i][j],max(dp[0][i - 1][j - 1] + 1, dp[1][i - 1][j] + 1));
			}
		}
	}
	int res = 0;

	for (int i = 0; i <= W+1; i++) {
		res = max(res, max(dp[0][T][i], dp[1][T][i]));
	}

	cout << res;
}