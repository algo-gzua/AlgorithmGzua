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
	
	// 도우가격, 토핑가격 , 도우열량
	int p_d, p_t, d_c;
	cin >> p_d >> p_t >> d_c;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	//피자의가격 money = a+b*k
	//피자의 열량 calorie = a+b

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