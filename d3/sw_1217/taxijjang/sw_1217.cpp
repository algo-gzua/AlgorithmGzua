#include<iostream>

int rec(int num, int cnt) {
	if (cnt == 0) {
		return 1;
	}
	return num * rec(num, cnt - 1);
}
int main(void) {
	for (int t = 1; t <= 10; t++) {
		int T;
		scanf("%d", &T);

		int N, M;
		scanf("%d %d", &N, &M);

		int sum = rec(N, M);

		printf("#%d %d\n", t, sum);
	}

	return 0;
}