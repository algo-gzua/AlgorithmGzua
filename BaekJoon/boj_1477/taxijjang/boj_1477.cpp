#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> rest;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, L; cin >> N >> M >> L;

	rest.push_back(0);
	rest.push_back(L);

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		rest.push_back(n);
	}

	sort(rest.begin(), rest.end());

	int r_size = rest.size();
	int left = 0, right = L, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		int cnt = 0;

		for (int i = 1; i < r_size; i++) {
			cnt += (rest[i] - rest[i - 1]- 1) / mid;
		}

		if (cnt > M)
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << left;
}