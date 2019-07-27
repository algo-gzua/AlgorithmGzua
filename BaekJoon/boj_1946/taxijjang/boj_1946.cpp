#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 100010

using namespace std;

vector<pair<int, int>> arr;

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N; scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			int a, b; scanf("%d %d", &a, &b);
			arr.push_back({ a,b });
		}

		sort(arr.begin(), arr.end());

		int cnt = 1;
		int left = arr[0].second;

		for (int i = 1; i < N; i++) {
			if (left < arr[i].second) {
				continue;
			}
			else if (left > arr[i].second) {
				cnt++;
				left = arr[i].second;
			}
		}
		vector<pair<int, int>> v;
		arr.swap(v);
		printf("%d\n", cnt);
	}
}