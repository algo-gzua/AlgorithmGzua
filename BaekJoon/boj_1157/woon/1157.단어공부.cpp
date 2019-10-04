#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


map<char, int> m;

int main() {


	string s;
	cin >> s;

	int len = s.length();
	char x;
	for (int i = 0; i < len; i++) {

		x = s[i];
		if (x >= 'a' && x <= 'z') {
			x = x - 32;
		}

		if (m.find(x) == m.end()) {
			m.insert({ x,1 });
		}
		else {
			m[x]++;
		}
	}

	string index = " ";
	int count = 0;
	int max = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {

		if (max <= iter->second) {
			
			if (max == iter->second) {
				count++;
			}
			else {
				index = iter->first;
				count = 0;
			}

			max = iter->second;
		}
	}
	
	if (count == 0) {
		cout << index;
	}
	else {
		cout << "?";
	}

	return 0;
}