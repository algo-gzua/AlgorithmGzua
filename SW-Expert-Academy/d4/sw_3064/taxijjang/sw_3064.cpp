#include<iostream>
#include<vector>

using namespace std;

int tree[400001];
int start_index;
//첫 번째 명령
void first_cmd(int index , int num) {
	int node = index + start_index -1;
	while (node > 0) {
		tree[node] += num;
		node /= 2;
	}
}

//두 번째 명령
int second_cmd(int left, int right) {
	int sum = 0;
	left += start_index - 1;
	right += start_index - 1;

	while (left <= right) {
		//left가 짝수 인덱스 일 때
		if (left % 2 == 1)
			sum += tree[left];

		//right가 홀수 인덱스 일 때
		if (right % 2 == 0) {
			sum += tree[right];
		}

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return sum;
}

void sum() {
	int node = start_index;
	while (node > 1) {
		for (int i = node; i < node * 2; i++) {
			tree[i / 2] += tree[i];
		}
		node /= 2;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);

		start_index = 1;

		while (start_index < N) {
			start_index *= 2;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d", &tree[start_index + i]);
		}

		sum();
		vector<int> result;

		for (int i = 0; i < M; i++) {
			int menu;
			scanf("%d", &menu);

			if (menu == 1) {
				int index, num;
				scanf("%d %d", &index, &num);

				first_cmd(index, num);
			}

			else if (menu == 2) {
				int left, right;
				scanf("%d %d", &left, &right);

				result.push_back(second_cmd(left, right));
			}
		}

		printf("#%d ", t);
		for (auto iter = result.begin(); iter != result.end(); iter++) {
			printf("%d ", *iter);
		}

		fill(tree, tree + 400001, 0);
	}
}