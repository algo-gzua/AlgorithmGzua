#include<iostream>
#include<algorithm>
#define SIZE 100010
using namespace std;

int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + N);
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int find; cin >> find;

		int left = 1, right = N, mid;

		bool check = false;
		while (left <= right) {
			mid = (left + right) / 2;

			if (mid == find) {
				check = true;
				break;
			}
			else if (mid < find)
				left = mid + 1;
			else
				right = mid - 1;

		}

		if (check)
			cout << "1\n";
		else
			cout << "0\n";
	}
}