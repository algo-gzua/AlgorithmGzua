#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;

	int here;
	v.push_back(0);

	for (int i = 0; i < n; i++) {
		cin >> here;

		if (here > v.back()) {
			v.push_back(here);
		}

		else {

			int left = 0;
			int right = v.size();

			while (left < right) {

				int mid = (left + right) / 2;

				if (v[mid] < here) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}

			v[right] = here;

		}
	}


	cout << v.size()-1;
	return 0;
}

