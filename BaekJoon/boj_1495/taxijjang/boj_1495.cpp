#include<iostream>
#define SIZE 1001
#include<vector>
using namespace std;

bool dp[SIZE][SIZE];
int V[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	int N, M, S; cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	dp[0][S] = true;

	for (int i = 1; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (dp[i - 1][j] == true) {
				if (j + V[i] >= 0 && j + V[i] <= M)
					dp[i][j + V[i]] = true;
				if (j - V[i] >= 0 && j - V[i] <= M)
					dp[i][j - V[i]] = true;
			}
		}
	}

	int res = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i])
			res = i;
	}

	cout << res;
	getchar();
}