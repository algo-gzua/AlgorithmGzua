#include<iostream>
#include<string>

using namespace std;

int word_cnt(char c) {
	int cnt = 0;

	switch (c) {
	case 'A': case 'D': case 'O':
	case 'P': case 'Q': case 'R':
		cnt = 1;
		break;
	case 'B':
		cnt = 2;
		break;
	default:
		break;
	}

	return cnt;
}
int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int a, b;
		string s1, s2;
		cin >> s1 >> s2;

		bool judge = true;

		if (s1.size() == s2.size()) {
			for (int i = 0; i < s1.size(); i++) {
				a = word_cnt(s1[i]);
				b = word_cnt(s2[i]);
				if (a != b) {
					judge = false;
				}
			}
		}
		if (s1.size() == s2.size() && judge) {
			printf("#%d SAME\n", t);
		}
		else {
			printf("#%d DIFF\n", t);
		}
	}
}
