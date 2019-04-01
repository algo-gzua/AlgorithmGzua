#include<iostream>

int arr[1010] = { 0 };

int max_(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	const int T = 10;

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 3; i <= N+2; i++) {
			scanf("%d", &arr[i]);
		}

		int cnt = 0;

		for (int i = 3; i <= N + 2; i++) {
			int max = arr[i - 2];
			for (int j = i - 2; j <= i + 2; j++) {
				if (i != j) {
					max = max_(max, arr[j]);
				}
			}
			if (arr[i] > max) cnt += arr[i] - max;
		}
	}
}