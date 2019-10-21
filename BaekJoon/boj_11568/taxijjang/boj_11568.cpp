#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define INF 2e9
using namespace std;

vector<int> v;
int dp[1001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;

	v.push_back(-INF);

	for (int i = 0; i < N; i++) {
		int num; cin >> num;

		if (v.back() < num) {
			v.push_back(num);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), num);
			*it = num;
		}
	}

	cout << v.size() - 1;
		
}