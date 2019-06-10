#include<iostream>
using namespace std;

int x[3] = { 0,0,-1 };
int y[3] = { 1,-1,0 };

int arr[101][101];
bool visited[101][101];
int result;
int answer;
void dfs(int here_x, int here_y) {
	visited[here_x][here_y] = true;

	if (here_x == 0) {
		answer = here_y;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (here_x + y[i] < 0 || here_y + y[i] > 99)
			continue;
		if (visited[here_x + x[i]][here_y + y[i]] != true) {
			if (arr[here_x + x[i]][here_y + y[i]] == 1) {
				dfs(here_x + x[i], here_y + y[i]);
				if (answer != 0) {
					break;
				}
			}
		}
	}
}

const int SIZE = 100;
int main(void) {
	for (int t = 1; t <= 10; t++) {
		int num;
		cin >> num;

		answer = 0;

		int de_x, de_y;
		fill(&visited[0][0], &visited[101][101], false);
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 2) {
					de_x = i;
					de_y = j;
				}
			}
		}


		dfs(de_x, de_y);

		printf("#%d %d\n", t, answer);
	}
}