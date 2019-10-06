#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int N; cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(),v.end());

	int res = 1;
	for (int i = 0; i < v.size(); i++) {
		if (res < v[i]) {
			break;
		}
		else {
			res += v[i];
		}
	}

	cout << res;
}