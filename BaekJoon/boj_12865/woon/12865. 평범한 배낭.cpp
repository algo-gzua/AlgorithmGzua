#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct INF{

	int w;
	int v;

}inf;

vector<inf> v;
int dp[102][100001];
bool cmp(const inf& p1, const inf& p2) {

	return p1.w < p2.w;

	if (p1.w == p2.w) {
		return p1.v < p2.v;
	}
}
int main() {

	int n, k;
	cin >> n >> k;

	inf bag;
	for (int i = 0; i <= n; i++) {

		if (i == 0) {
			v.push_back({ 0,0 });
		}
		else {
			cin >> bag.w >> bag.v;
			v.push_back(bag);
		}
	}
	sort(v.begin(), v.end(), cmp);

	int start = v[1].w;
	for (int i = 1; i <= n; i++) {
		for (int j = start; j <= k; j++) {

			if (j >= v[i].w) {
				dp[i][j] = max(dp[i - 1][j], v[i].v + dp[i - 1][j - v[i].w]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			
		}
		
	}


	cout << dp[n][k];

	return 0;
}