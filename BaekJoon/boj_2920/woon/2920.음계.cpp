#include <iostream>
using namespace std;

int n[8];
int main() {

	
	for (int i = 0; i <8; i++) {
		cin >> n[i];
	}

	int result = 0;
	for (int i = 0; i < 7; i++) {
		if (n[i] + 1 == n[i + 1]) {
			result = 1;
		}
		else if (n[i] - 1 == n[i + 1]) {
			result = 2;
		}
		else {
			result = 3;
			break;
		}
	}

	if (result == 1) {
		cout << "ascending";
	}
	else if (result == 2) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
	return 0;
}