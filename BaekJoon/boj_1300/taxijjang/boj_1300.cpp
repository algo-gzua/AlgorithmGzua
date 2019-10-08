#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;

	int left = 1, right = K, mid, res = 0, cnt;

	while (left <= right) {
		cnt = 0;
		mid = (left + right) / 2;

		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}

		if (cnt < K)
			left = mid + 1;
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res;
}