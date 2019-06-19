#include<iostream>
#include<algorithm>

#define INF 1000000001
#define SIZE 400000
using namespace std;

int tree[SIZE];

int tree_size(int N) {
	int size = 1;
	while (size < N) size *= 2;
	return size;
}

void f_tree(int size, int N) {
	int start = size;
	while (start > 1) {
		for (int i = start; i < start * 2; i += 2)
			tree[i / 2] = min(tree[i], tree[i + 1]);
		start /= 2;
	}
}

void index_tree(int a, int b, int start) {
	int m = INF;
	int left = start + a - 1;
	int right = start + b - 1;

	while (left < right) {
		//left È¦¼ö ÀÎµ¦½º ÀÏ¶§
		if (left % 2 == 1) {
			m = min(m, tree[left]);
		}
		//right°¡ Â¦¼ö ÀÏ¶§
		if (right % 2 == 0) {
			m = min(m, tree[right]);
		}

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}
	if (left == right)
	{
		m = min(m, tree[left]);
	}
	printf("%d\n", m);
}
int main(void) {
	int N, M; scanf("%d %d", &N, &M);
	int size = tree_size(N);

	fill(tree, tree + SIZE, INF);
	for (int i = size; i < size + N; i++)
		scanf("%d", &tree[i]);

	f_tree(size, N);

	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		index_tree(a, b, size);
	}
}
