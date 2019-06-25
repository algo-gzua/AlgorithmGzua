#include<iostream>
#include<algorithm>

using namespace std;
int arr[202];

int main(void) {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N, K; scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		float rank = 0;

		sort(arr, arr + N);

		for(int i = N-K ;i < N ; i ++){
			rank = (rank + (float)(arr[i])) / 2;
		}
		printf("#%d %.6f\n", t,rank);
	}
}