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
		// 1�� 5�� ������ �������°��
		if (n % 5 == 0) {
			cal(n);
		}
		// 2�� 5�� ������ �������� �������
		// 3���� ����ؼ� ���ش�.
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