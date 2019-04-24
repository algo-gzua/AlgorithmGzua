#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		stack<int> num;
		stack<char> kiho;
		for (int i = 0; i < N;i++) {
			if (i % 2 == 0) {
				int n;
				scanf("%d", &n);
				num.push(n);
			}
			else if (i % 2 != 0) {
				char k;
				scanf("%c", &k);
				kiho.push(k);
			}
		}

		while (num.size() != 1) {
			char k = kiho.top();
			kiho.pop();

			int n1 = num.top(); num.pop();
			int n2 = num.top(); num.pop();

			switch (k) {
			case '+':
				num.push(n1 + n2);
				break;
			case '-':
				num.push(n1 - n2);
				break;
			case '*':
				num.push(n1 * n2);
				break;
			case '/':
				num.push(n1 / n2);
				break;
			}
		}

		printf("#%d %d\n", t, num.top());


	}
}