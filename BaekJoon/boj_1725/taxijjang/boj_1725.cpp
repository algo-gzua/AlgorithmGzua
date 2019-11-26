#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<stack>

#define INF 2e9
#define SIZE 101000

using namespace std;

typedef long long int ll;

stack<int> _stack;
int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int res = 0;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	_stack.push(0);

	for (int i = 1; i <= N + 1; i++) {
		int s_top = _stack.top();
		while (!_stack.empty() && arr[_stack.top()] > arr[i]) {
			int here = arr[_stack.top()];
			_stack.pop();
			int cnt = i - _stack.top() - 1;

			res = max(res, here*cnt);
		}
		_stack.push(i);
	}

	cout << res;
}