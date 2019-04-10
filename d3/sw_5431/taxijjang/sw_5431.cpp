#include<iostream>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, K;
		scanf("%d %d", &N, &K);

		int people[101] = { 0 };

		for (int i = 1; i <= K; i++) {
			int num;
			scanf("%d", &num);

			people[num] = 1;
		}

		printf("#%d ", t);
		for (int i = 1; i <= N; i++) {
			if (people[i] != 1)
				printf("%d ", i);
		}
	}
}