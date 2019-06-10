#include<iostream>

using namespace std;
//╩С ©Л го аб
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

const int SIZE = 16;
int arr[17][17];
bool visited[17][17];
int result;

void dfs(int here_x, int here_y) {
	visited[here_x][here_y] = true;

	if (arr[here_x][here_y] == 3) {
		result = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (visited[here_x + x[i]][here_y + y[i]] != true) {
			dfs(here_x + x[i], here_y + y[i]);
			if (result == 1) break;
		}
	}
}
int main(void) {
	int T;
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &T);
		result = 0;
		fill(&visited[0][0], &visited[17][17], false);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				scanf("%1d", &arr[i][j]);
				if (arr[i][j] == 1) {
					visited[i][j] = true;
				}
			}
		}

		dfs(1, 1);
		printf("#%d %d\n", T, result);
	}
}