#include <iostream>
using namespace std;


int f;
bool flag = false;

void cal(int n) {

	f = n / 5;
	flag = true;
}

int main() {

	int n;
	cin >> n;

	int count = 0;
	while (flag == false) {
		// 1번 5로 나누어 떨어지는경우
		if (n % 5 == 0) {
			cal(n);
		}
		// 2번 5로 나누어 떨어지지 않을경우
		// 3으로 계속해서 빼준다.
		else {
			if (n >= 3) {
				n = n - 3;
				count++;
				if (n == 0) {
					flag = true;
				}
			}	
			else {
				break;
			}
		}
	}
	int sum = 0;
	sum = f + count;

	if (flag == true) {
		cout << sum;
	}
	else if (flag ==false) {
		cout << "-1";
	}



	return 0;
}