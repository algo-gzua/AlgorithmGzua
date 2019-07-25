#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


priority_queue<int, vector<int>, greater<int>> pq;
map<int, bool> m;
int main() {

	vector<int> v;
	int k, n;

	cin >> k >> n;

	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		v.push_back(x);

		if (m[x] == false) {
			m.insert(pair<int, bool>(v[i], true));
			pq.push(v[i]);
		}
	}





	return 0;
}

