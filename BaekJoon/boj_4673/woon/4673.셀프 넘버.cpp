#include <iostream>
using namespace std;

int self_number(int i) {

	int n;
	int sum = i;
	while ( i > 0) {

		n = i % 10;
		sum = sum + n;
		i = i / 10;
	
	}
	return sum;
}

bool check[30000];
int main() {


	for (int i = 1; i <= 10000; i++) {
		int x = self_number(i);

		check[x] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (check[i] == false) {
			cout << i << endl;
		}
	}

	return 0;
}