#include<iostream>
#include<algorithm>
#include<queue>
#define SIZE 1010
using namespace std;

int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int arr[SIZE][SIZE];

queue<pair<int, int>> q;

int main(void) {
	int N, M; scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		pair<int, int> here = q.front();
		q.pop();

		int h_x = here.first;
		int h_y = here.second;

		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];

			if (n_x < 0 || n_x >= M || n_y < 0 || n_y >= N) continue;
			if (arr[n_x][n_y] != 0) continue;
			if (arr[n_x][n_y] == 0) {
				arr[n_x][n_y] = arr[h_x][h_y] + 1;
				q.push({ n_x,n_y });
			}
		}
	}

	int m_n = 0;
	bool judge = true;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
			m_n = max(arr[i][j], m_n);
		}
	}

	printf("%d", m_n - 1);

	return 0;
}