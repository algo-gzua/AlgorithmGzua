#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE 110

using namespace std;

typedef struct Data {
	int h, x, y;
}Data;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };

int arr[SIZE][SIZE][SIZE];

queue<Data> q;
int main(void) {
	ios::sync_with_stdio(false);
	int M, N, H; cin >> M >> N >> H;

	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> arr[h][x][y];
				if (arr[h][x][y] == 1)
					q.push({ h,x,y });
			}
		}
	}

	while (!q.empty()) {
		Data here = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			Data next;
			next.h = here.h + dh[i];
			next.x = here.x + dx[i];
			next.y = here.y + dy[i];

			if (next.h < 0 || next.x < 0 || next.y <0 || next.h >=H || next.x >= N || next.y>=M)
				continue;
			if (arr[next.h][next.x][next.y] != 0)
				continue;
			if (arr[next.h][next.x][next.y] == 0) {
				arr[next.h][next.x][next.y] = arr[here.h][here.x][here.y] + 1;
				q.push(next);
			}
		}
	}

	int m_n = 0;
	bool judge = true;
	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (arr[h][x][y] == 0) {
					cout << -1;
					return 0;
				}
				m_n = max(arr[h][x][y], m_n);
			}
		}
	}

	cout << m_n;
}