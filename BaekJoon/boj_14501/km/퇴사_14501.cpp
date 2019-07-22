#include <iostream>

struct Node 
{
	int T;
	int P;
};

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int dp[16] = { 0, };
	Node nodes[16];

	for (int i = 1; i <= N; ++i) 
	{
		int t, p;

		cin >> t >> p;

		nodes[i] = { t, p };
	}

	for (int i = N; i > 0; --i) 
	{
		if (nodes[i].T + i > N + 1)
			continue;

		int max = nodes[i].P;

		for (int j = i + nodes[i].T; j <= N; ++j) 
		{
			max = max >= nodes[i].P + dp[j] ? max : nodes[i].P + dp[j];
		}

		dp[i] = max;
	}

	int result = 0;

	for (int i = 1; i <= N; ++i) 
	{
		result = result >= dp[i] ? result : dp[i];
	}

	cout << result;

	return 0;
}