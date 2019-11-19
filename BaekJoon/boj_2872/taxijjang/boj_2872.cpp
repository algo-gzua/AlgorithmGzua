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

vector<int> arr;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int res = N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}


	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] == res)
			res--;
	}

	cout << res;
}