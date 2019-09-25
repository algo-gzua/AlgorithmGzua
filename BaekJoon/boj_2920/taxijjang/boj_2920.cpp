#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	
	string a = "12345678", d = "87654321";
	string s = "";

	for (int i = 0; i < 8; i++) {
		int n; cin >> n; 
		s += to_string(n);
	}

	if (a == s)
		cout << "ascending";
	else if (a == d)
		cout << "descending";
	else
		cout << "mixed";
}