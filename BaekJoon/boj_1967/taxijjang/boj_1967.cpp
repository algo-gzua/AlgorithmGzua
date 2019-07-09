#include<iostream>
#include<vector>
#define SIZE 10001

using namespace std;

vector<pair<int, int>> tree[SIZE];
bool visited[SIZE];

typedef struct Data {
	int loc = 0;
	int m_cnt = 0;
}Data;

Data m;
void dfs(int here, int w) {
	visited[here] = true;
	for (auto n : tree[here]) {
		if (visited[n.first] != true) {
			if (m.m_cnt < n.second + w) {
				m.loc = n.first; m.m_cnt = n.second + w;
			}
			dfs(n.first, n.second+w);
		}
	}

}
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);

		tree[n1].push_back({ n2,w });
		tree[n2].push_back({ n1,w });
	}

	dfs(1, 0);

	int s_n = m.loc;
	m.m_cnt = 0;

	fill(visited, visited + SIZE, false);
	dfs(s_n, 0);

	printf("%d", m.m_cnt);
}