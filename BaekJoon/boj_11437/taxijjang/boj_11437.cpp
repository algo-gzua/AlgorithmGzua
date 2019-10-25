#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 50500
#define MAX_DEPTH 20
using namespace std;

typedef long long int ll;

vector<int> tree[SIZE];
int parrent[SIZE][MAX_DEPTH];
int depth[SIZE];

// parrent , depth를 -1로 초기화
void fill() {
	for (int i = 0; i < SIZE; i++) {
		depth[i] = -1;
		for (int j = 0; j < MAX_DEPTH; j++) {
			parrent[i][j] = -1;
		}
	}
}

//트리를 구성 하기
void make_tree(int here) {
	for (auto next : tree[here]) {
		if (depth[next] == -1) {
			parrent[next][0] = here;
			depth[next] = depth[here] + 1;
			make_tree(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 1. 트리를 만들기(parrent[curr][0]을 채워줌, depth[u]또한 채워준다.
	// 2. 2중 반복문을 이용하여 parrent[u][2^k]를 채워준다
	// 3. 쿼리에 있는 공통 조상을 구한다
	// 4. 입력으로 받은 depth[u] 와 depth[v]가 다를경우 같게 만들어준다
	// 5. depth를 같게 만든 후 부모가 다를경우 맨 밑의 dpeth부터 루트노드 까지 부모를 비교해 준다

	int N; cin >> N;
	for (int n = 0; n < N - 1; n++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	fill();
	//루트노드의 깊이 는 0 이다
	depth[1] = 0;

	//트리를 구성 하기
	make_tree(1);

	//parrent[u][k]를 채우기
	for (int dep = 0; dep < MAX_DEPTH; dep++) {
		for (int node = 1; node < SIZE; node++) {
			if (parrent[node][dep] != -1) {
				parrent[node][dep + 1] = parrent[parrent[node][dep]][dep];
			}
		}
	}

	//query 입력

	int query; cin >> query;
	for (int q = 0; q < query; q++) {
		int u, v; cin >> u >> v;

		//depth[u] >= depth[v] 로 만들어 주기 위해
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		//어려운것 
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

		cout << u << "\n";
	}

}