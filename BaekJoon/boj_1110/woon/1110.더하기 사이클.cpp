#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	//십의 자리 일의 자리
	int a, b, x, c;

	x = n;

	// 결과값
	int result = 0;
	int count = 0;

	if (n == 0) {
		count = 1;
	}
	else if(n != 0){
		while (x != result) {

			a = n / 10;
			b = n % 10;
			c = a + b;


			result = (c % 10) + (b * 10);
			n = result;
			count++;
		}
	}

	cout << count;
	return 0;
}