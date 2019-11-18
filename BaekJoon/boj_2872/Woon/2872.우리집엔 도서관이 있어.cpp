#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int index;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == n) {
			index = i;
		}

		v.push_back(x);
	}


	int now = n;
	int count = 1;
	for (int i = index-1; i >= 0; i--) {
		if (v[i] == now - 1) {
			now = v[i];
			count++;
		}
	}

	int result = n - count;
	cout <<result;
	return 0;
}