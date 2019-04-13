#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		stack<char> s1;// (
		stack<char> s2;// [
		stack<char> s3;// {
		stack<char> s4;// <

		int judge = 1;

		string brk;
		cin >> brk;

		for (int i = 0; i < N; i++) {

			if (brk[i] == '(') {
				s1.push(brk[i]);
			}
			else if (brk[i] == '[') {
				s2.push(brk[i]);
			}
			else if (brk[i] == '{') {
				s3.push(brk[i]);
			}
			else if (brk[i] == '<') {
				s4.push(brk[i]);
			}
			
			else if (brk[i] == ')') {
				if (s1.empty())
					judge = 0;
				else
					s1.pop();
			}
			else if (brk[i] == ']') {
				if (s2.empty())
					judge = 0;
				else
					s2.pop();
			}
			else if (brk[i] == '}') {
				if (s3.empty())
					judge = 0;
				else
					s3.pop();
			}
			else if (brk[i] == '>') {
				if (s4.empty())
					judge = 0;
				else
					s4.pop();
			}

			if (judge == 0)
				break;
		}
		printf("#%d %d\n", t, judge);
	}
}