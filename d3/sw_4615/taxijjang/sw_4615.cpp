#include<iostream>

using namespace std;

int map[11][11];

int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { -1,0,1,1,1,0,-1,-1 };

int N;

void action(int h_x, int h_y, int color) {
	map[h_x][h_y] = color;

	for (int i = 0; i < 8; i++) {
		int n_x = h_x + x[i];
		int n_y = h_y + y[i];

		while (n_x > 0 && n_x <= N && n_y > 0 && n_y <= N) {
			int X = h_x, Y = h_y;
			if (map[n_x][n_y] == 0)
				break;
			else if (map[n_x][n_y] == map[h_x][h_y]) {
				while ((X != n_x) || (Y != n_y)) {
					map[X][Y] = color;
					X += x[i];
					Y += y[i];
				}
				n_x += x[i];
				n_y += y[i];
			}
			else {
				n_x += x[i];
				n_y += y[i];
			}
		}
	}

}
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int M;
		scanf("%d %d", &N, &M);

		//1 - Èæ , 2 - ¹é
		map[N / 2][N / 2] = 2;
		map[(N / 2) + 1][(N / 2) + 1] = 2;
		map[N / 2][(N / 2) + 1] = 1;
		map[(N / 2) + 1][N / 2] = 1;


		for (int i = 0; i < M; i++) {
			int xx, yy, color;
			scanf("%d %d %d", &xx, &yy, &color);
			action(xx, yy, color);
		}

		int black = 0;
		int white = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 1) black++;
				else if (map[i][j] == 2) white++;
			}
		}

		printf("#%d %d %d\n", t, black, white);
		fill(&map[0][0], &map[11][11], 0);
	}
}