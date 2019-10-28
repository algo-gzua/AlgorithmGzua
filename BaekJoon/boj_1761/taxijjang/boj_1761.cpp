#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define MAX_DEPTH 20
#define SIZE 10101

using namespace std;

typedef long long int ll;

int parrent[SIZE][MAX_DEPTH];
int depth[SIZE];
vector<pair<int, int>> tree[SIZE];
int len[SIZE];

void fill() {
	for (int i = 0; i < SIZE; i++) {
		depth[i] = -1;
		for (int j = 0; j < MAX_DEPTH; j++) {
			parrent[i][j] = -1;
		}
	}
}

void make_tree(int here, int cost) {
	len[here] = cost;
	for (auto next : tree[here]) {
		if (depth[next.first] == -1) {
			parrent[next.first][0] = here;
			depth[next.first] = depth[here] + 1;
			make_tree(next.first , cost + next.second);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		int u, v, cost; cin >> u >> v >> cost;
		tree[u].push_back({ v,cost });
		tree[v].push_back({ u,cost });
	}

	fill();
	depth[1] = 0;
	make_tree(1, 0);

	for (int dep = 0; dep < MAX_DEPTH; dep++) {
		for (int node = 1; node < SIZE; node++) {
			if (parrent[node][dep] != -1)
				parrent[node][dep + 1] = parrent[parrent[node][dep]][dep];
		}
	}

	int M; cin >> M; 
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		int tmp_u = u, tmp_v = v;
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int i = 0; diff; i++) {
			if (diff % 2 != 0)
				u = parrent[u][i];
			diff /= 2;
		}

		if (u != v) {
			for (int i = MAX_DEPTH - 1; i >= 0; i--) {
				if (parrent[u][i] != -1 && parrent[u][i] != parrent[v][i]) {
					u = parrent[u][i];
					v = parrent[v][i];
				}
			}
			u = parrent[u][0];
		}
	
		cout << (len[tmp_u] - len[u]) + (len[tmp_v] - len[u]) << "\n";
	}
}