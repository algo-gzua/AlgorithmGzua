#include<iostream>
#include<algorithm>

#define SIZE 101
#define INF 99999999
using namespace std;

int arr[SIZE][SIZE];

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int T, N; scanf("%d %d", &T, &N);
		
		fill(&arr[0][0], &arr[SIZE][SIZE], INF);

		for (int i = 0; i < N; i++) {
			int v1, v2; scanf("%d %d", &v1, &v2);
			arr[v1][v2] = 1;
		}

		for (int k = 0; k < SIZE-1; k++) {
			for (int i = 0; i < SIZE-1; i++) {
				for (int j = 0; j < SIZE-1; j++) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}

		int res = 0;
		if (arr[0][99] != INF) {
			res = 1;
		}
		printf("#%d %d\n", T, res);
	}
}