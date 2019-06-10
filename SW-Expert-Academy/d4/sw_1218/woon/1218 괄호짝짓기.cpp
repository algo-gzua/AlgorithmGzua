#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int main() {

	int tc;	
	int n;
	string s;
	

	for (tc = 0; tc < 10; tc++) {
		stack<char> st;
		cin >> n;

		cin >> s;
	
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') {
				st.push(s[i]);
			}

			else if (s[i] == ')' && st.top() == '(') {
				st.pop();
			}
			else if (s[i] == '}' && st.top() == '{') {
				st.pop();
			}
			else if (s[i] == ']' && st.top() == '[') {
				st.pop();
			}
			else if (s[i] == '>' && st.top() == '<') {
				st.pop();
			}
			else {
				st.push(s[i]);
			}

		}
		if (st.empty()) {
			cout << "#" << tc + 1 <<" "<< 1 << endl;
		}
		else {
			cout << "#" << tc+1 << " " << 0 << endl;
		}
	}
	return 0;
}