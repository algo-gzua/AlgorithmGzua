#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

ll dp[70][10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = i+1;
	}

	for (int i = 2; i <= 64; i++) {
		for (int j = 9; j >= 0; j--) {
			dp[i][0] = 1;
			for (int j = 1; j < 10; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		cout << dp[N][9] << "\n";
	}
}