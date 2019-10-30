#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int cost[10001];
bool visited[10001];
int c_count = 0;

void dfs(int here) {

	int len = v[here].size();

	for (int i = 0; i < len; i++) {
		if (visited[v[here][i]] == false) {
			visited[v[here][i]] = true;

			c_count++;
			dfs(v[here][i]);
			// 빠져나올때		
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;


	int a, b;

	v[0].push_back(-1);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {

		visited[i] = true;
		dfs(i);
		cost[i] = c_count;

		for (int j = 1; j <= n; j++) {
			visited[j] = false;
		}
		c_count = 0;

	}


	int result = 0;

	for (int i = 1; i <= n; i++) {
		result = max(result, cost[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (result == cost[i]) {
			cout << i << " ";
		}
	}

	return 0;
}