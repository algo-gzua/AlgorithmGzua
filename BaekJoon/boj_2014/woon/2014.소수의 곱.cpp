#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


priority_queue<int, vector<int>, greater<int>> pq;
bool check[100001];
int main() {

	vector<int> v;
	int k, n;

	cin >> k >> n;

	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		v.push_back(x);

		if (!check[x]) {
			pq.push(v[i]);
			check[x] = true;
		}
	}

	int top;
	int result;
	for (int i = 0; i < n; i++) {

		top = pq.top();
		pq.pop();

		for (int j = 0; j < k; j++) {
			result = top * v[j];

			if (!check[result]) {
				pq.push(result);

			}
			else {
				continue;
			}
		}
	}

	cout << top;




	return 0;
}