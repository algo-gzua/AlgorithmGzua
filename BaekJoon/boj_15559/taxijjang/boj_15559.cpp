#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

char arr[SIZE][SIZE];
int visited[SIZE][SIZE];

map<char, int> dx;
map<char, int> dy;

int cnt = 1;
int res = 0;
void init_dx() {
	dx['N'] = -1;
	dy['N'] = 0;

	dx['S'] = 1;
	dy['S'] = 0;

	dx['W'] = 0;
	dy['W'] = -1;

	dx['E'] = 0;
	dy['E'] = 1;
}

void dfs(int h_x, int h_y){
	if (visited[h_x][h_y] != 0) {
		if(visited[h_x][h_y] == cnt)
			res++;
		cnt++;
		return;
	}

	visited[h_x][h_y] = cnt;

	int n_x = h_x + dx[arr[h_x][h_y]];
	int n_y = h_y + dy[arr[h_x][h_y]];

	dfs(n_x, n_y);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	init_dx();

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
			}
		}
	}


	cout << res;

}