#include<iostream>
#define SIZE 100100
#include<algorithm>
using namespace std;

typedef long long int ll;
ll arr[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	ll left = 1, right = 1e18 , mid, cnt, res = 2e10;

	while (left <= right) {
		mid = (right + left) / 2;
		cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += mid / arr[i];
		}

		if (cnt >= M) {
			res = res < mid ? res : mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << res;
}