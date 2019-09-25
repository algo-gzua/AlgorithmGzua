#include<iostream>
#include<algorithm>
#define SIZE 200010
using namespace std;

int arr[SIZE];

int n, c;
bool check(int mid) {
	int cnt = 1;
	int here = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - here >= mid) {
			cnt++;
			here = arr[i];
		}
	}

	return cnt >= c ? true : false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	int left = 1;
	int right = 1000000000;

	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (check(mid))
			left = mid+1;
		else
			right = mid-1;
	}
	cout << left-1;
}