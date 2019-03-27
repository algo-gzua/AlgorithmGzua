#include<iostream>

int arr[15][15];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);

		arr[1][1] = 1;
		
		for (int i = 2; i <= n; i++) {
			arr[i][1] = arr[i - 1][1];
			for (int j = 2; j < i; j++) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			arr[i][i] = arr[i - 1][i - 1];
		}

		printf("#%d\n", t);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}