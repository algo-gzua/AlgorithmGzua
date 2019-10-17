#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

#define SIZE 40
#define INF 2e9
using namespace std;

typedef struct Data {
	int l, r, c, cnt = 0;
}Data;

int dl[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };

char arr[SIZE][SIZE][SIZE];
bool visited[SIZE][SIZE][SIZE];

void fill() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				arr[i][j][k] = NULL;
				visited[i][j][k] = false;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	do {
		int L, R, C; cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			break;
		Data start;
		bool check = false;
		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					cin >> arr[l][r][c];
					if (arr[l][r][c] == 'S' && check == false) {
						start.l = l; start.r = r; start.c = c;
						check = true;
					}
				}
			}
		}

		queue<Data> q;

		q.push(start);

		int res = INF;
		while (!q.empty()) {
			Data h = q.front();
			visited[h.l][h.r][h.c] = true;

			if (arr[h.l][h.r][h.c] == 'E') {
				res = res < h.cnt ? res : h.cnt;
			}
			q.pop();

			for (int i = 0; i < 6; i++) {
				Data n;
				n.l = h.l + dl[i];
				n.r = h.r + dr[i];
				n.c = h.c + dc[i];
				n.cnt = h.cnt + 1;

				if (n.l < 0 || n.r < 0 || n.c < 0 || n.l >= L || n.r >= R || n.c >= C)
					continue;
				if (visited[n.l][n.r][n.c] == true)
					continue;
				if (arr[n.l][n.r][n.c] == '#')
					continue;

				visited[n.l][n.r][n.c] = true;
				q.push(n);
			}
		}
		if (res == INF) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << res << " minute(s).\n";
		}
	} while(1);
}