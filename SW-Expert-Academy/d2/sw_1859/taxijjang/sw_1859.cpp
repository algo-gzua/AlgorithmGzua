#include<iostream>

using namespace std;

int arr[1000001];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int num;
		scanf("%d", &num);

		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}

		int sum = 0;
		int cnt = 0;
		int max = arr[num - 1];
		int result = 0;

		for (int i = num - 2; i >= 0; i--) {
			if (max <= arr[i]) {
				result += (max *cnt) - sum;
				sum = 0;
				cnt = 0;
				max = arr[i];
			}
			else if (max > arr[i]) {
				sum += arr[i];
				cnt++;
			}
		}
		result += (max*cnt) - sum;
		printf("#%d %d\n", t, result);
	}
}