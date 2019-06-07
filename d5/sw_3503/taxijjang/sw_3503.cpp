#include<iostream>
#include<deque>
#include<algorithm>
#include<cmath>
#define SIZE 100001
using namespace std;

int arr[SIZE];
deque<int> dq;

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int tt; scanf("%d", &tt);
		for (int i = 0; i < tt; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + tt);

		dq.push_front(arr[0]);
		for (int i = 1; i < tt; i++) {
			if (i % 2 == 1) dq.push_front(arr[i]);
			else dq.push_back(arr[i]);
		}

		int res = 0;
		for (int i = 0; i < tt; i++) {
			if (i == tt - 1) res = res < abs(arr[i] - arr[0]) ? abs(arr[i] - arr[0]) : res;
			else res = res < abs(arr[i] - arr[i + 1]) ? abs(arr[i] - arr[i + 1]) : res;
		}

		printf("#%d %d\n", t, res);

		dq.clear();
		fill(arr, arr + SIZE, 0);
	}
}