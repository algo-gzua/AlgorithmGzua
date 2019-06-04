#include<iostream>
#include<string>
#include<set>

using namespace std;

set<int> s_set;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int arr[4][4];

void dfs(int h_x, int h_y, int n, int cnt) {
	if (cnt == 7) {
		s_set.insert(n);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		if (n_x >= 0 && n_x < 4 && n_y >= 0 && n_y < 4)
			dfs(n_x, n_y, (n*10) + arr[n_x][n_y], cnt+1);
	}
}
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		s_set.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string s = "";
				int cnt = 1;
				dfs(i, j, arr[i][j], cnt);
			}
		}

		printf("#%d %d\n", T, s_set.size());
	}
}