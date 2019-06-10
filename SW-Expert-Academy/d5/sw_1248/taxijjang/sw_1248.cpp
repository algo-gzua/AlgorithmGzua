#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[50002];
int parent[50002][18];
int dph[50002];
bool visited[50002];
bool sub_tree_v[50002];
int sub_size;
void dfs(int here, int depth) {
	visited[here] = true;
	dph[here] = depth;
	for (auto next : tree[here]) {
		if (visited[next] != true) {
			parent[next][0] = here;
			dfs(next, depth + 1);
		}
	}
}
void sub_tree_dfs(int here) {
	sub_size++;
	sub_tree_v[here] = true;
	for (auto next : tree[here]) {
		if (sub_tree_v[next] != true) {
			sub_tree_dfs(next);
		}
	}
}
int main(void) {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int V, E; scanf("%d %d", &V, &E);
		int u, v; scanf("%d %d", &u, &v);

		for (int e = 0; e < E; e++) {
			int a, b; scanf("%d %d", &a, &b);
			tree[a].push_back(b);
		}

		dfs(1, 1);

		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= V; i++) {
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}
		
		while (1) {
			if (dph[u] > dph[v])
				u = parent[u][0];
			else if (dph[u] < dph[v])
				v = parent[v][0];
			else
				break;
		}
		while (u != v) {
			u = parent[u][0];
			v = parent[v][0];
		}

		sub_size = 0;
		sub_tree_dfs(u);
		printf("#%d %d %d\n", t, u, sub_size);

	}
}