#include<iostream>
#define SIZE 110

int arr[SIZE][SIZE];

int main(void) {
	int N, C; scanf("%d%d", &N, &C);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	int j, res = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 1;
		for (j = 1; j < N; j++) {
			//가로
			if (arr[i][j] == arr[i][j + 1]) 
				cnt++;
			else if (arr[i][j] + 1 == arr[i][j + 1] && cnt >= C)
				cnt = 1;
			else if (arr[i][j] - 1 == arr[i][j + 1] && cnt >= 0)
				cnt = 1 - C;
			else
				break;
		}
		if (j == N && cnt >= 0) res++;
		cnt = 1;
		for (j = 1; j < N; j++) {
			//세로
			if (arr[j][i] == arr[j + 1][i])
				cnt++;
			else if (arr[j][i] + 1 == arr[j + 1][i] && cnt >= C) 
				cnt = 1;
			else if (arr[j][i] - 1 == arr[j + 1][i] && cnt >= 0) 
				cnt = 1 - C;
			else break;
		}
		if (j == N && cnt >= 0) res++;

	}
	printf("%d", res);
}