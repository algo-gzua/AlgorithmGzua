#include <iostream>
#include <algorithm>

using namespace std;

long long dp[101];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;

	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int t = 1; t <= T; ++t)
	{
		int N;

		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}