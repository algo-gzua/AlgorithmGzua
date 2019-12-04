#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int size = s.length();
	sort(s.begin(), s.end());

	int count = 0;
	do {
		bool check = true;
		for (int i = 0; i < size - 1; i++) {
			if (s[i] == s[i + 1]) {
				check = false;
				break;
			}
		}
		if (check == true) {
			count++;
		}

	} while (next_permutation(s.begin(), s.end()));

	cout << count;
	return 0;
}