#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;


int main() {

	int n, i, p, tc;
	int result = 0;
	char s,o;


	map<char, int> m;

	m.insert(make_pair('+', 1));
	m.insert(make_pair('-', 1));
	m.insert(make_pair('*', 2));
	m.insert(make_pair('/', 2));

	vector<char> v; // 입력받을 배열
	vector<char> postifix;

	vector<char> vclear;
	vector<char> pclear;
	
	stack<char> oper;

	for (tc = 0; tc < 10; tc++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}

		/*for (i = 0; i < n; i++) {
			cout << v[i];
		}
		cout << endl;*/

		int length = v.size();

		// 후위 표기로 만들기
		for (i = 0; i < length; i++) {
			//연산자가 아니라면
			if (v[i] >= 48 && v[i] <= 57) {
				postifix.push_back(v[i]);
			}
			// 연산자라면
			else {
				// 연산자스택이 비어있지 않고, 연산자스택에 우선순위가 들어오는 연산자의 우선순위
				// 보다 크다면 ( * -> +)

				while (!oper.empty() && m[oper.top()] >= m[v[i]]) {
					// (*, /) 빼주고
					postifix.push_back(oper.top());
					oper.pop();

				}
				// (+.-) 넣어준다	
				oper.push(v[i]);
			}
		}
		//연산자 스택에 남아있더면 후위 배열에 넣어줌
		while (!oper.empty()) {
			postifix.push_back(oper.top());
			oper.pop();
		}


		// 후위 계산법
		stack<int> num;
		int size = postifix.size();

		while (num.size() != 1) {
			//피연산자는 스택에 넣어준다
			for (i = 0; i < size; i++) {
				if (postifix[i] >= 48 && postifix[i] <= 57) {
					num.push(postifix[i] - '0');
				}
				else {
					// 연산자를 만났을때
					if (postifix[i] == '+') {

						int n1 = num.top();
						num.pop();

						int n2 = num.top();
						num.pop();

						num.push(n1 + n2);
					}

					else if (postifix[i] == '-') {

						int n1 = num.top();
						num.pop();

						int n2 = num.top();
						num.pop();

						num.push(n1 - n2);
					}

					else if (postifix[i] == '*') {

						int n1 = num.top();
						num.pop();

						int n2 = num.top();
						num.pop();

						num.push(n1 * n2);
					}

					else if (postifix[i] == '/') {

						int n1 = num.top();
						num.pop();

						int n2 = num.top();
						num.pop();

						num.push(n1 / n2);
					}
				}
			}
		}
		result = num.top();
		printf("#%d %d\n",tc+1,result);

		// 벡터 메모리 해제
		v.swap(vclear);
		vclear.clear();
		v.clear();

		postifix.swap(pclear);
		pclear.clear();
		postifix.clear();
	}
	
	/*for (i = 0; i < n; i++) {
		cout << postifix[i];
	}*/

	return 0;
}
