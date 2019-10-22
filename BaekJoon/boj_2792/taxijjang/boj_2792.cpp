#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#define INF 2e9
using namespace std;

typedef long long int ll;

vector<int> color;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	ll max_val = 0;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		color.push_back(num);
		max_val = max_val < num ? num : max_val;
	}

	ll left = 1, right = max_val, mid;
	ll res = INF;
	while (left <= right) {
		mid = (left + right) / 2;
		ll man_cnt = 0;
		for (auto it = color.begin(); it != color.end(); it++) {
			man_cnt += *it / mid;
			if (*it%mid != 0)
				man_cnt++;
		}

		if (man_cnt > N)
			left = mid + 1;
		else if (man_cnt <= N) {
			right = mid - 1;
			res = res > mid ? mid : res;
		}
	}
	cout << res;
}