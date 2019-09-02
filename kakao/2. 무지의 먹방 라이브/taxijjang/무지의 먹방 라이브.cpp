#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
typedef long long int ll;
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}
int solution(vector<int> food_times, ll k) {

	vector<pair<int, int>> f;
	int food_size = food_times.size();

	for (int i = 0; i < food_size; i++) {
		f.push_back({ food_times[i], i + 1 });
	}

	sort(f.begin(), f.end());

	int size = f.size();
	int tmp = 0;
	for (auto it = f.begin(); it != f.end(); it++, size--) {
		ll gap = (ll)(it->first - tmp)*size;
		if (gap == 0)
			continue;
		if (gap <= k) {
			k -= gap;
			tmp = it->first;
		}
		else {
			sort(it, f.end(), cmp);
			return (it + (k%size))->second;
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);

	vector<int> f;
	f.push_back(3);
	f.push_back(1);
	f.push_back(2);
	ll k = 5;

	cout << solution(f, k);
}