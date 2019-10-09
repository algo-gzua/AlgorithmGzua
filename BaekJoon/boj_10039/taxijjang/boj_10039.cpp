#include<iostream>

using namespace std;

int main(void) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int num; cin >> num;
		num = num < 40 ? 40 : num;
		sum += num;
	}
	cout << sum / 5;
}