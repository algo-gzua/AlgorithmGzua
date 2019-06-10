#include<iostream>
#include<vector>
#define SIZE 100

using namespace std;

vector<int> arr[SIZE];
bool visited[SIZE];

bool result = false;
void dfs(int here) {
	if (here == 99) {
		result = true;
		return;
	}
	visited[here] = true;

	for (auto v : arr[here]) {
		if (visited[v] != true) {
			dfs(v);
		}
	}
}
int main(void) {
	for (int t = 1; t <= 10; t++) {
		int T, cnt;
		scanf("%d %d", &T, &cnt);

		for (int i = 0; i < cnt; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			arr[a].push_back(b);
		}
		dfs(0);
		printf("#%d %d\n", T, result == true ? 1 : 0);
		result = false;
		fill(visited, visited + SIZE, false);
		for (int i = 0; i < SIZE; i++) {
			arr[i].clear();
		}
	}
}