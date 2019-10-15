#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int find(int a) {

	int size = v.size();
	int left = 0, right = (size - 1);

	while (left <= right) {

		int mid = (left + right) / 2;
		if (a > v[mid]) {
			left = mid + 1;
		}
		else if (a < v[mid]) {
			right = mid-1;
		}
		else { 
			return 1;
		}
	}

	return 0;
}
int main() {

	int n;
	scanf("%d", &n);

	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int m;
	scanf("%d", &m);


	int a;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);

		printf("%d\n",find(a));
	}

	return 0;
}