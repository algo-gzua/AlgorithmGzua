#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main() {



	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	// ���찡��, ���ΰ��� , ���쿭��
	int p_d, p_t, d_c;
	cin >> p_d >> p_t >> d_c;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	//�����ǰ��� money = a+b*k
	//������ ���� calorie = a+b

	int money = p_d;
	int calorie = d_c;
	int result = 0;
	int max = 0;

	for (int i = n - 1; i >= 0; i--) {
		
		result = calorie / money;
		if (result > max) {
			max = result;
		}

		money = money + p_t;
		calorie = calorie + v[i];
		
		
	}

	cout << max;
	return 0;
}