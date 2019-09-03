#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string s1 = "";
	int len = t * m;


	//구할 범위
	for (int i = 0; i < len; i++) {

		string s = "";
		// 몫 나머지
		int mok = i;
		int res = 0;
		while (true) {
			// 1 ~ 10진수까지

			if (n <= 10) {

				res = mok % n;
				mok = mok / n;
				
				s = to_string(res) + s;
				if (mok == 0) {
					break;
				}
			}
			// 11 ~ 16진수까지
			else {

				//나머지가 11이상
				res = mok % n;
				mok = mok / n;

				if (res >= 10) {
					char c = res + 55;
					s = c + s;
				}
				else {
					s = to_string(res) + s;
				}
				if (mok == 0) {
					break;
				}
			}
		}
		s1 = s1 + s;
	}

	// 말해야할것들 찾기
	int k = 0;
	while (true) {

		if (k == t) {
			break;
		}

		answer = answer + s1[p - 1];

		p = p + m;
		k++;
	}

	return answer;
}
int main() {

	//int n = 2;
	//int t = 4;
	//int m = 2;
	//int p = 1;

	int n = 16;
	int t = 16;
	int m = 2;
	int p = 2;

	cout << solution(n, t, m, p);

	return 0;
}