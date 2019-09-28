#include <iostream>
#include <string>
using namespace std;

int main() {

	int t, tc;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		string quiz;
		cin >> quiz;

		int len = quiz.length();
		int count = 0;
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (quiz[i] =='O') {
				count++;
			}
			else {
				count = 0;
			}
			sum = sum + count;

		}
		cout << sum << endl;
	}
	return 0;
}