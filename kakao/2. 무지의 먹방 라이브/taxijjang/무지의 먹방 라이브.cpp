#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
typedef long long int ll;
using namespace std;

int solution(vector<int> food_times, ll k) {

	vector<int> f; f.resize((int)food_times.size());
	copy(food_times.begin(), food_times.end(), f.begin());

	sort(f.begin(), f.end());

	ll sum = 0;
	ll k_mok, k_na;
	int f_size = f.size();
	ll size = f.size();
	int tmp = 0;
	int res = -1;

	if (k / size > f[f_size - 1])
		return res;

	for (int i = 0; i < f_size; i++) {
		k_mok = k / size; k_na = k%size;
		if (tmp == f[i]) {
			size--;
			continue;
		}
		tmp = f[i];
		if ((k_mok < f[i] + sum) || k_mok == 0) {
			break;
		}
		else if (k_mok >= f[i] + sum) {
			k = k - (size * (f[i] - sum));
			sum += f[i] - sum;
			size--;
		}
	}
	int food_size = food_times.size();

	int cnt = 0;
	bool check = false;
	int index;
	for (int i = 0; i < food_size; i++) {
		if (food_times[i] <= sum) {
			if (k_mok == 0)
				cnt++;
			continue;
		}

		if (cnt == k_na) {
			index = i;
			check = true;
			break;
		}
		cnt++;
	}
	res = index + 1;
	return res;
}