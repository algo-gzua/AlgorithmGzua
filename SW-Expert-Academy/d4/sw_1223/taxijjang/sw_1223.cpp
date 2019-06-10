#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		string s;
		cin >> s;

		stack<char> kiho;

		string post;
		for (int i = 0; i < N; i++) {
			if (s[i] >= '0' && s[i] <= '9')
				post += s[i];
			else {
				switch (s[i]) {
				case '*':
					while (!kiho.empty() && (kiho.top() == '*')) {
						post += kiho.top();
						kiho.pop();
					}
					kiho.push(s[i]);
					break;
				case '+':
					while (!kiho.empty()) {
						post += kiho.top();
						kiho.pop();
					}
					kiho.push(s[i]);
					break;
				}

			}
		}
		int p_idx = 0;
		while (!kiho.empty()){
			post += kiho.top();
			kiho.pop();
		}


		stack<int> num;
		int p_size = post.size();

		for (int i = 0; i < p_size; i++) {
			if (post[i] >= '0' && post[i] <= '9') {
				num.push(post[i] - '0');
			}
			else {
				int n1 = num.top(); num.pop();
				int n2 = num.top(); num.pop();

				if (post[i] == '*')
					num.push(n1*n2);
				else if (post[i] == '+')
					num.push(n1 + n2);
			}
		}
		//cout << post << "\n";
		printf("#%d %d", t, num.top());
	}
}