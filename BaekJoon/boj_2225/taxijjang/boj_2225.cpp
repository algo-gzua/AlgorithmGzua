#include<iostream>
#define SIZE 201
#define MOD 1000000000
long long int arr[SIZE][SIZE];

int main(void) {
	int N, K; scanf("%d %d", &N, &K);

	for (int i = 1; i < SIZE; i++) {
		arr[1][i] = i;
	}
	for (int i = 2; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (j == 1)
				arr[i][j] = 1;
			else if (j == 2)
				arr[i][j] = i + 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i][j-1])%MOD;
		}
	}

	printf("%lld", arr[N][K]);
}