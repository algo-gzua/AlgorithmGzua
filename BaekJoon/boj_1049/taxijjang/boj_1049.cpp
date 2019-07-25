#include<iostream>
#define SIZE 52
#define INF 1111

int main(void) {
	int N, M; scanf("%d %d", &N, &M);

	int pa = INF, nat = INF;
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		pa = pa > a ? a : pa;
		nat = nat > b ? b : nat;
	}

	int res = 0;
	if (pa >= nat * 6) {
		res = nat * N;
	}
	else {
		int mok = N / 6;
		int na = N % 6;
		res += mok * pa;
		if (pa >= na * nat)
			res += na*nat;
		else
			res += pa;
	}
	printf("%d", res);
}