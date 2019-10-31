#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 10100

using namespace std;

typedef long long int ll;

vector<pair<int, int>> arr;
int dp[110][SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N; cin >> T >> N;

	arr.push_back({ 0,0 });

	for (int i = 0; i < N; i++) {
		int cost, cnt; cin >> cost >> cnt;
		arr.push_back({ cost,cnt });
	}

	sort(arr.begin(), arr.end());
	dp[0][0] = 1;
	//dp[K][N] -> K는 사용한 동전의 가짓 수, N은 금액 
	for (int K = 1; K <= N; K++) {
		for (int cnt = 0; cnt <= arr[K].second; cnt++) {//사용하는 동전의 갯수
			for (int cost = 0; cost <= T; cost++) {//K의 동전으로 만들수 있는 금액
				if (cost + cnt*arr[K].first > T) break;
				dp[K][cost + cnt*arr[K].first] += dp[K - 1][cost];
			}
		}
	}

	cout << dp[N][T];
	getchar();

}