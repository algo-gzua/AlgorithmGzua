#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 10100

using namespace std;

typedef long long int ll;

vector<int> v[SIZE];
vector<bool> visited;
int cost[SIZE];
int cnt = 0;
void dfs(int here) {
	visited[here] = true;

	for (auto next : v[here]) {
		if (visited[next] != true) {
			cnt++;
			dfs(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}

	int max_cnt = -1;
	for (int i = 1; i <= N; i++) {
		visited.assign(SIZE, false);
		cnt = 0;
		dfs(i);
		max_cnt = max_cnt < cnt ? cnt : max_cnt;
		cost[i] = cnt;
	}

	for (int i = 1; i <= N; i++) {
		if (max_cnt == cost[i])
			cout <<i << " ";
	}

}