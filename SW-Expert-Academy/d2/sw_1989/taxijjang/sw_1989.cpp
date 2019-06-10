#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;

		int s_size = s.size();

		bool judge = true;
		for (int i = 0; i <= s_size / 2; i++) {
			if (s[i] != s[s_size - 1 - i]) {
				judge = false;
				break;
			}
		}

		if (judge) {
			printf("#%d %d\n", t,1);
		}
		else {
			printf("#%d %d\n", t,0);
		}
		

	}
}