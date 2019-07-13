#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#define SIZE 53
using namespace std;

char arr[SIZE][SIZE];
bool visited[SIZE][SIZE] = { false, };

int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };

typedef struct Data {
	int x = 0;
	int y = 0;
	int cnt = 0;
}Data;
int main(void) {
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j-1];
		}
	}
	int m_cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 'L') {
				int m = 0;
				queue<Data> q;
				pair<int, int> h = { i,j };
				visited[i][j] = true;
				Data d; d.x = i, d.y = j, d.cnt = 0;
				q.push(d);

				while (!q.empty()) {
					int h_x = q.front().x;
					int h_y = q.front().y;
					int h_cnt = q.front().cnt;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int n_x = h_x + x[i];
						int n_y = h_y + y[i];

						if (visited[n_x][n_y] == true)
							continue;
						if (n_x < 1 || n_y <1 || n_x > N || n_y>M)
							continue;
						if (arr[n_x][n_y] == 'W')
							continue;

						Data d2; d2.x = n_x, d2.y = n_y, d2.cnt = h_cnt + 1;
						visited[n_x][n_y] = true;
						q.push(d2);
					}
					if (q.empty()) {
						m_cnt = max(m_cnt, h_cnt);
					}
				}
				fill(&visited[0][0], &visited[SIZE][SIZE], false);
			}

		}
	}
	printf("%d", m_cnt);

}