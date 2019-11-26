#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> m;
int p[100001];
int num[100001];

int _find(int x) {
	if (p[x] == x) {
		return x;
	}
	else {
		return p[x] = _find(p[x]);
	}
}


int _union(int a, int b) {

	int root_a = _find(a);
	int root_b = _find(b);

	if (root_a != root_b) {
		p[root_a] = root_b;
		num[root_b] = num[root_b] + num[root_a];
		num[root_a] = 1;
	}

	return num[root_b];
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, tc;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		int f;
		cin >> f;

		for (int i = 0; i < 100001; i++) {
			p[i] = i;
			num[i] = 1;
		}

		string a,b;
		int index = 1;

		for (int i = 0; i < f; i++) {
			cin >> a >> b;

			if (m.find(a) == m.end()) {
				m.insert({ a, index });
				index++;
			}

			if (m.find(b) == m.end()) {
				m.insert({ b, index });
				index++;
			}
			cout << _union(m[a], m[b]) << "\n";
		}
	}
	return 0;
}