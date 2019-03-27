#include<iostream>
#define MAX 1000
using namespace std;

typedef struct data {
	int score=0;
	int cnt = 0;
}Data;
int arr[MAX];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		Data d;

		fill(arr, arr + MAX, 0);
		for (int i = 0; i < MAX; i++) {
			int num = 0;
			scanf("%d", &num);
			arr[num]++;
			if (d.cnt < arr[num]) {
				d.cnt = arr[num];
				d.score = num;
			}
			else if (d.cnt == arr[num]) {
				if (d.score < num) {
					d.score = num;
				}
			}

		}

		printf("#%d %d\n", N, d.score);

	}

	getchar();
}