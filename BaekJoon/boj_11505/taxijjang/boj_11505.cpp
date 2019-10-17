#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

#define MOD 1000000007
#define SIZE 3000300
using namespace std;

typedef long long int ll;
ll arr[SIZE];

void fill_arr() {
	for (int i = 0; i < SIZE; i++)
		arr[i] = 1;
}
int start_index(int N) {
	int i = 1;
	while (N > i) {
		i *= 2;
	}
	return i;
}

void init(int start) {
	for (int i = start * 2 - 2; i > 0; i-=2) {
		arr[i / 2] = (arr[i] * arr[i+1])%MOD;
	}

}

void change(int index, int change_num, int start) {
	int origin_num = arr[index];
	arr[index] = change_num;
	for (int i = index; i > 0; i /= 2) {
		if (i % 2 == 0) {
			arr[i / 2] = arr[i] * arr[i + 1];
		}
		else {
			arr[i / 2] = arr[i] * arr[i - 1];
		}
	}
}

void print(int left, int right) {
	ll res = 1;

	while (left <= right) {
		if (left % 2 != 0) {
			res *= arr[left];
			left++;
		}
		if (right % 2 != 1) {
			res *= arr[right];
			right--;
		}

		left /= 2; right /= 2;
	}

	cout << res % 1000000007 << "\n";
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	fill_arr();
	int start = start_index(N);

	for (int i = start; i < start + N; i++) {
		cin >> arr[i];
	}

	init(start);

	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			int change_index = start + b - 1;
			change(change_index, c ,start);
		}
		else {
			int left = start + b - 1;
			int right = start + c - 1;
			print(left, right);
		}
	}

}