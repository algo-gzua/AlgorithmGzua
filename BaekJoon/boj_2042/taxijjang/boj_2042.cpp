#include<iostream>
#define SIZE 21000000

typedef long long int ll;
ll tree[SIZE];

ll t_size(ll N) {
	ll t = 1;
	while (t <= N) {
		t *= 2;
	}
	return t;
}

void tree_sum(ll start, ll end) {
	for (int i = end; i > 1; i--) {
		tree[i / 2] += tree[i];
	}
}

void change_num(ll index, ll num) {
	ll gap = num - tree[index];
	while (index >= 1) {
		tree[index] += gap;
		index /= 2;
	}
}

ll section_sum(ll left, ll right, ll t_s) {
	ll sum = 0;
	left += t_s - 1;
	right += t_s - 1;
	while (left <= right) {
		if (left % 2 == 1)
			sum += tree[left];
		if (right % 2 == 0)
			sum += tree[right];

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}
	return sum;
}
int main(void) {
	int N, M, K; scanf("%d %d %d", &N, &M, &K);

	ll t_s = t_size(N);

	for (int n = t_s; n < t_s + N; n++) {
		scanf("%d", &tree[n]);
	}

	tree_sum(t_s, t_s * 2 - 1);


	for (int i = 0; i < M + K; i++) {
		int menu; scanf("%d", &menu);

		if (menu == 1) {
			ll b, c; scanf("%lld %lld", &b, &c);
			ll index = t_s + b - 1;
			change_num(index, c);
		}
		else {
			ll b, c; scanf("%lld %lld", &b, &c);
			printf("%lld\n", section_sum(b, c, t_s));
		}
	}
}