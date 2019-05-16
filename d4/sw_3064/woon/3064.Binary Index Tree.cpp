#include <iostream>
#include <array>
#include <vector>
using namespace std;

int arr[1000];
int bit[1000];


void update(int bit[], int index, int val, int n) {

	while (index <= n) {

		bit[index] = bit[index] + val;
		index = index + (index & -index);

	}
}

int sum(int bit[], int i) {

	int ret = 0;
	while (i > 0) {
		ret = ret + bit[i];
		i -= (i & -i);
	}

	return ret;
}

int main() {

	int i, n, count, tc, t;
	int check = 0;

	scanf("%d", &t);
	for (tc = 1; tc <= t; tc++) {

		scanf("%d %d", &n, &count);
		for (i = 1; i <= n; i++) {

			cin >> arr[i];

			// 인덱스트리로 바꿔주는 곳
			update(bit, i, arr[i], n);
		}

		int num, index, val;
		vector<int> v;

		// num = 1 (update) , num = 2 (sum)
		for (i = 0; i < count; i++) {
			scanf("%d %d %d", &num, &index, &val);
			switch (num)
			{
			case 1:
				update(bit, index, val, n);
				break;

			case 2:
				v.push_back(sum(bit, val) - sum(bit, index - 1));
				check++;
				break;

			default:
				break;
			}

		}
		printf("#%d ", t);
		for (i = 0; i < check; i++) {
			printf("%d ", v[i]);
		}

	}
	return 0;
}

