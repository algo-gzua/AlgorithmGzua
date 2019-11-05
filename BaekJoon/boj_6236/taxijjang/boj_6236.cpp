#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> cost;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	int min_cost = 0;
	for (int i = 0; i < N; i++) {
		int day; cin >> day;
		cost.push_back(day);
		min_cost = min_cost > day ? min_cost : day;
	}

	int left = min_cost, right = INF, mid;
	int res = INF;
	while (left <= right) {
		mid = (left + right) / 2;
		int tmp = 0;
		int K = 0;
		for (auto it = cost.begin(); it != cost.end(); it++) {
			if (tmp < *it) {
				K++;
				tmp = mid - *it;
			}
			else {
				tmp -= *it;
			}
		}

		if (M < K) {
			left = mid + 1;
		}
		else {
			res = res < mid ? res : mid;
			right = mid - 1;
		}
	}
	cout << res;
}