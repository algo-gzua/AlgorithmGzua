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

	vector<char> v; // �Է¹��� �迭
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

		// ���� ǥ��� �����
		for (i = 0; i < length; i++) {
			//�����ڰ� �ƴ϶��
			if (v[i] >= 48 && v[i] <= 57) {
				postifix.push_back(v[i]);
			}
			// �����ڶ��
			else {
				// �����ڽ����� ������� �ʰ�, �����ڽ��ÿ� �켱������ ������ �������� �켱����
				// ���� ũ�ٸ� ( * -> +)

				while (!oper.empty() && m[oper.top()] >= m[v[i]]) {
					// (*, /) ���ְ�
					postifix.push_back(oper.top());
					oper.pop();

				}
				// (+.-) �־��ش�	
				oper.push(v[i]);
			}
		}
		//������ ���ÿ� �����ִ��� ���� �迭�� �־���
		while (!oper.empty()) {
			postifix.push_back(oper.top());
			oper.pop();
		}


		// ���� ����
		stack<int> num;
		int size = postifix.size();

		while (num.size() != 1) {
			//�ǿ����ڴ� ���ÿ� �־��ش�
			for (i = 0; i < size; i++) {
				if (postifix[i] >= 48 && postifix[i] <= 57) {
					num.push(postifix[i] - '0');
				}
				else {
					// �����ڸ� ��������
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

		// ���� �޸� ����
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
