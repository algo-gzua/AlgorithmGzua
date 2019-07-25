#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {


	int pack[50];
	int item[50];

	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		cin >> pack[i] >> item[i];
	}

	sort(pack, pack + m);
	sort(item, item + m);

	if (n > 6) {
		if (n % 6 == 0) {
			if (pack[0] > item[0] * 6) {
				cout << item[0] * n;
			}
			else if (pack[0] <= item[0] * 6) {
				cout << pack[0] * (n / 6);
			}
		}
		else {
			if (pack[0] > item[0] * 6) {
				cout << item[0] * n;
			}
			else {
				if (pack[0] > item[0] * (n % 6)) {
					cout << ((pack[0] * (n / 6)) + (item[0] * (n % 6)));
				}
				else {
					cout << (pack[0] * ((n / 6) + 1));
				}
			}
		}
	}
	else if (n <= 6) {
		if (n % 6 == 0) {
			if (pack[0] > item[0] * 6) {
				cout << item[0] * n;
			}
			else if (pack[0] <= item[0] * 6) {
				cout << pack[0] * (n / 6);
			}
		}
		else {
			if (pack[0] > item[0] * n) {
				cout << item[0] * n;
			}
			else {
				cout << pack[0];
			}
		}
	}

	return 0;
}