#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> stk;

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		string s;
		cin >> s;

		int s_size = s.size();

		int result = 1;

		for (int i = 0; i < s_size; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
				stk.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>') {
				char top = stk.top();

				if (s[i] == ')') {
					if (top == s[i] - 1) {
						stk.pop();
					}
					else {
						result = 0;
						break;
					}
				}
				else if (s[i] == ']' || s[i] == '}' || s[i] == '>') {
					if (top == s[i] - 2) {
						stk.pop();
					}
					else {
						result = 0;
						break;
					}
				}
			}
		}

		printf("#%d %d\n", t, result);
	}
}