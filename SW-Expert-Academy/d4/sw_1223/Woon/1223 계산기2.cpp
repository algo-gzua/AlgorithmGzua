#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;

int main() {


	int i, n, tc;
	int result = 0;

	// 연산자랑 우선순위 넣어주기
	map<char, int> m;

	m.insert(make_pair('(', 0));
	m.insert(make_pair('+', 1));
	m.insert(make_pair('-', 1));
	m.insert(make_pair('*', 2));
	m.insert(make_pair('/', 2));


	//수식 입력받는 vector 배열
	vector<char> v;
	//후위표기법
	vector<char> postifix;
	//연산자 스택
	stack<char> oper;
	stack<int> num;

	for (tc = 0; tc < 10; tc++) {
		scanf("%d", &n);

		// 수식 넣기
		for (i = 0; i < n; i++) {
			char s;
			cin >> s;
			v.push_back(s);
		}

		//중위 연산 -> 후위 연산으로 바꾸기

		int length = v.size();
		for (i = 0; i < length; i++) {
			// 연산자가 아닌 숫자라면

			if (v[i] >= 48 && v[i] <= 57) {
				postifix.push_back(v[i]);
			}
			//연산자라면

			else {
				if (v[i] == '(') {
					// '(' 일 경우 무조건 연산자스택에 넣기
					oper.push(v[i]);
				}
				else if (v[i] == ')') {
					// ')' 일 경우 연산자 스택에 있는거 전부다 빼기
					// 스택에 꼭대기 부터 차근차근 후위표기 배열에 넣기
					while (!oper.empty()) {
						if (oper.top() == '(') {
							oper.pop();
							break;
						}
						postifix.push_back(oper.top());
						oper.pop();
					}
				}
				else {
					// 스택에 연산자 우선순위에 따라 배열하기
					while (!oper.empty() && m[oper.top()] >= m[v[i]]) {
						postifix.push_back(oper.top());
						oper.pop();
					}
					oper.push(v[i]);
				}

			}
		}
		while (!oper.empty()) {
			postifix.push_back(oper.top());
			oper.pop();
		}

		// 중위 -> 후위 확인
		/*for (i = 0; i < n; i++) {
			cout << postifix[i];
		}*/

		int size = postifix.size();

		//후위표기법 계산
		for (i = 0; i < size; i++) {
			if (postifix[i] >= 48 && postifix[i] <= 57) {
				num.push(postifix[i] - '0');
			}
			else {
				if (postifix[i] == '+') {
					int n1 = num.top();
					num.pop();
					int n2 = num.top();
					num.pop();

					num.push(n1 + n2);
				}
				if (postifix[i] == '-') {
					int n1 = num.top();
					num.pop();
					int n2 = num.top();
					num.pop();

					num.push(n1 - n2);
				}
				if (postifix[i] == '*') {
					int n1 = num.top();
					num.pop();
					int n2 = num.top();
					num.pop();

					num.push(n1 * n2);
				}
				if (postifix[i] == '/') {
					int n1 = num.top();
					num.pop();
					int n2 = num.top();
					num.pop();

					num.push(n1 / n2);
				}
			}
		}
		result = num.top();
		cout << "#" << tc + 1 << " " << result << endl;


		v.clear();
		postifix.clear();
	}
	return 0;
}