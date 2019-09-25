#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	int N; cin >> N;
	
	for (int n = 1; n <= N; n++) {
		string s; cin >> s;
		int res = 0 , cnt = 0, sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'X') {
				cnt = 0;
			}
			else {
				cnt++;
				res += cnt;
			}
		}
		cout << res << "\n";
	}
}