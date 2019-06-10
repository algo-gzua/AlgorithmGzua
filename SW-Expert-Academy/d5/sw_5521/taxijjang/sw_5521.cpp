#include<iostream>
#include<vector>
#define MAX 600

using namespace std;


vector<int> frd[MAX];
bool visited[MAX];
int cnt,depth;

void dfs(int here) {
	if (visited[here] != true) cnt++;
	visited[here] = true;

	for (auto v : frd[here]) {
		if (visited[v] != true) {
			if (++depth < 3) {
				dfs(v);
			}
			depth--;
		}	
	}
	

}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);

		

		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			frd[a].push_back(b);
			frd[b].push_back(a);
		}

		cnt = 0, depth = 0;
		visited[1] = true;
		for (auto v : frd[1]) {
			depth = 1;
			dfs(v);
		}

		printf("#%d %d\n", t, cnt );

		fill(visited, visited + MAX ,false);
		for (int i = 0; i < MAX; i++) {
			frd[i].clear();
		}
	}
}