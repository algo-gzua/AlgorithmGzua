#include <iostream>
using namespace std;

int tri[101];
int main() {

	int t, tc, n;
	cin >> t;

	for (tc = 0; tc < t; tc++) {


		cin >> n;


		tri[0] = 1;
		tri[1] = 1;
		tri[2] = 1;
		tri[3] = 2;

		for (int i = 4; i < n; i++) {

			tri[i] = tri[i - 3] + tri[i - 2];

		}

		cout << tri[n - 1];

	}
	return 0;
}