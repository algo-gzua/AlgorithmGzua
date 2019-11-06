#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 101000

using namespace std;

typedef long long int ll;

ll parrent[SIZE];
ll dist[SIZE];
bool visited[SIZE];

vector<pair<ll, ll>> tree[SIZE];
vector<pair<int, int>> query;
int N, M;

void fill_() {
	for (int i = 0; i <= N; i++) {
		parrent[i] = i;
		dist[i] = 0;
		tree[i].clear();
		visited[i] = false;
	}
	query.clear();
}
int find(int node) {
	if (parrent[node] == node)
		return node;
	else {
		return parrent[node] = find(parrent[node]);
	}
}
bool _union(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot)
		return 0;
	else {
		parrent[bRoot] = aRoot;
		return 1;
	}
}

void make_tree(pair<ll, ll> here) {
	visited[here.first] = true;
	dist[here.first] = here.second;
	for (auto next : tree[here.first]) {
		if (visited[next.first] != true) {
			next.second += here.second;
			make_tree(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		fill_();
		for (int i = 1; i <= M; i++) {
			char menu; cin >> menu;
			if (menu == '!') {
				ll a, b, cost; cin >> a >> b >> cost;
				if (a > b) { swap(a, b); cost *= -1; }
				if (_union(a, b)) {
					tree[a].push_back({ b,cost });
					tree[b].push_back({ a,-cost });
				}
			}
			else if (menu == '?') {
				ll a, b; cin >> a >> b;
				if (find(a) != find(b)) {
					query.push_back({ -1,-1 });
				}
				else
					query.push_back({ a,b });
			}
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] != true)
				make_tree({ i,dist[i] });
		}

		for (int i = 0; i < query.size(); i++) {
			if (query[i].first == -1 && query[i].second == -1) {
				cout << "UNKNOWN\n"; continue;
			}
			else {
				cout << dist[query[i].second] - dist[query[i].first] << "\n";
			}
		}
	}
}