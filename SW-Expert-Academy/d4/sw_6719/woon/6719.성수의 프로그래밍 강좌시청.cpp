#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int t, tc;

	// n�� ���� �� , k �� ��û�� ���� ��
	int n, k;

	// ���� �迭
	vector<double> m;

	cin >> t;
	for (tc = 0; tc < t; tc++) {
		vector<double>().swap(m);

		cin >> n >> k;

		double m1;
		for (int i = 0; i < n; i++) {
			cin >> m1;
			m.push_back(m1);
		}

		sort(m.begin(), m.end());
		int size = m.size();

		// �Ƿ�
		double a = 0;
		for (int i = n - k; i < n; i++) {
			a = (a + m[i]) / 2;
		}

		cout << a;
	}



	return 0;
}