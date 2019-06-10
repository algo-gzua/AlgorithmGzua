#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;

int main() {


	int i, n, tc;
	int result = 0;

	// �����ڶ� �켱���� �־��ֱ�
	map<char, int> m;

	m.insert(make_pair('(', 0));
	m.insert(make_pair('+', 1));
	m.insert(make_pair('-', 1));
	m.insert(make_pair('*', 2));
	m.insert(make_pair('/', 2));


	//���� �Է¹޴� vector �迭
	vector<char> v;
	//����ǥ���
	vector<char> postifix;
	//������ ����
	stack<char> oper;
	stack<int> num;

	for (tc = 0; tc < 10; tc++) {
		scanf("%d", &n);

		// ���� �ֱ�
		for (i = 0; i < n; i++) {
			char s;
			cin >> s;
			v.push_back(s);
		}

		//���� ���� -> ���� �������� �ٲٱ�

		int length = v.size();
		for (i = 0; i < length; i++) {
			// �����ڰ� �ƴ� ���ڶ��

			if (v[i] >= 48 && v[i] <= 57) {
				postifix.push_back(v[i]);
			}
			//�����ڶ��

			else {
				if (v[i] == '(') {
					// '(' �� ��� ������ �����ڽ��ÿ� �ֱ�
					oper.push(v[i]);
				}
				else if (v[i] == ')') {
					// ')' �� ��� ������ ���ÿ� �ִ°� ���δ� ����
					// ���ÿ� ����� ���� �������� ����ǥ�� �迭�� �ֱ�
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
					// ���ÿ� ������ �켱������ ���� �迭�ϱ�
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

		// ���� -> ���� Ȯ��
		/*for (i = 0; i < n; i++) {
			cout << postifix[i];
		}*/

		int size = postifix.size();

		//����ǥ��� ���
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