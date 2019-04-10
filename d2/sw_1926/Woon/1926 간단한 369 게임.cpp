#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	//  input 숫자 1~n까지 찍기 -> 문자열
	//a%b=c;
	int n;
	int a, b, c;

	cin >> n;
	if (n >= 10 && n < 1000) {
		for (int i = 1; i <= n; i++) {
			int count = 0;
			a = i;
			do {
				c = a % 10;
				if (c == 3 || c == 6 || c == 9) {
					count++;
				}
				a = a / 10;

			} while (a != 0);

			if (count == 0) {
				cout << i << " ";
			}
			else {
				for (int j = 0; j < count; j++) {
					cout << "-";
				}
				cout << " ";
			}

		}
	}
	return 0;
}