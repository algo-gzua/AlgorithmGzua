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

int parrent[SIZE];
int num[SIZE];

using namespace std;

typedef long long int ll;

void fill_p() {
	for (int i = 0; i < SIZE; i++) {
		parrent[i] = i;
		num[i] = 1;
	}
}

int _find(int node) {
	if (parrent[node] == node)
		return node;
	else {
		return parrent[node] = _find(parrent[node]);
	}
}
int _union(int a, int b) {
	int aRoot = _find(a);
	int bRoot = _find(b);

	if (aRoot != bRoot) {
		parrent[aRoot] = bRoot;
		num[bRoot] += num[aRoot];
		num[aRoot] = 1;
	}

	return num[bRoot];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int F; cin >> F;
	for (int f = 1; f <= F; f++) {
		fill_p();
		map<string, int> _map;
		int index = 1;
		int N; cin >> N;

		for (int n = 1; n <= N; n++) {
			string a, b; cin >> a >> b;

			if (_map.find(a) == _map.end()) {
				_map[a] = index++;
			}

			if (_map.find(b) == _map.end()) {
				_map[b] = index++;
			}

			cout << _union(_map[a], _map[b]) <<"\n";
		}
	}

}