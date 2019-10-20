#include <iostream>
#include <string>
using namespace std;

int main() {

	string a, b;
	cin >> a >> b;

	char tmp_a = a[2];
	a[2] = a[0];
	a[0] = tmp_a;

	char tmp_b = b[2];
	b[2] = b[0];
	b[0] = tmp_b;

	if (a > b) {
		cout << a;
	}
	else {
		cout << b;
	}
	


	return 0;
}