#include <iostream>
using namespace std;

int main() {

	int a;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (a < 40) {
			sum = sum + 40;
		}
		else {
			sum = sum + a;
		}
	}

	int avg = sum / 5;

	cout << avg;
	return 0;
}