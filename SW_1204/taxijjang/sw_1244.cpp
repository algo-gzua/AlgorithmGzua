#include<iostream>
#include<algorithm>
#include <string>

using namespace std;
int result;

void dfs(string num, int change, int cnt, int here) {
	if (cnt == change) { result = max(result, stoi(num)); return; }
	else {
		int n_size = num.size();
		bool judge = false;
		for (int i = here; i < n_size - 1; i++) {
			for (int j = i + 1; j < n_size; j++) {
				if (num[i] <= num[j]) {
					char tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
					dfs(num, change, cnt + 1, i);
					tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
					judge = true;
				}
			}
		}

		if (!judge) {
			char tmp = num[n_size - 2];
			num[n_size - 2] = num[n_size - 1];
			num[n_size - 1] = tmp;
			dfs(num, change, cnt + 1, 0);
			tmp = num[n_size - 2];
			num[n_size - 2] = num[n_size - 1];
			num[n_size - 1] = tmp;
		}
	}
}

int main(void) {
	int C;
	scanf("%d", &C);

	for (int c = 1; c <= C; c++) {
		string num;
		cin >> num;

		int change;
		scanf("%d", &change);

		result = 0;

		dfs(num, change, 0, 0);

		printf("#%d %d\n", c , result);
	}
}