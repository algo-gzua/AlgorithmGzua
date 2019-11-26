#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, L;
	cin >> n >> m >> L;

	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}
	v.push_back(L);
	sort(v.begin(), v.end());

	int size = v.size();
	int left = 0, right = L;
	int mid = 0;

	while (left <= right) {

		mid = (left + right) / 2;
		int count = 0;

		for (int i = 1; i < size; i++) {
			count = count + (v[i] - v[i - 1] - 1) / mid;
		}

		if (count > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << left;






	return 0;
}