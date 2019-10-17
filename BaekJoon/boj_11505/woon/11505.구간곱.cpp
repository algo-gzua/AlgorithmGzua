#include <iostream>
using namespace std;

long long tree[3000000];

void init(int size, int n) {

	while (size > 1) {

		for (int i = size; i < size + n; i = i+2) {
			tree[i / 2] = tree[i] * tree[i + 1];
		}

		size = size / 2;
	}
}

void update(int x, int y,int size,int n) {
	
	int now = x + size - 1;
	tree[now] = y;

	while (now > 1) {
		
		if (now % 2 == 0) {
			tree[now / 2] = tree[now] * tree[now + 1];
		}
		else {
			tree[now / 2] = tree[now] * tree[now - 1];
		}
		now = now / 2;
	}
}

int mul(int x, int y, int size) {

	int left = x + size - 1;
	int right = y + size - 1;


	long long result = 1;
	while (left < right) {

		if (left % 2 != 0) {
			result = (result * tree[left])% 1000000007;
			left = left + 1;
		}
		if(right % 2 == 0) {
			result = (result * tree[right]) % 1000000007;
			right = right - 1;
		}

		left = left / 2;
		right = right / 2;
	}

	if (left == right) {
		result = (result * tree[left]);
	}

	return result % 1000000007;
}

int main() {


	int n, m, k;
	cin >> n >> m >> k;


	int size = 1;
	while (size < n) {
		size = size * 2;
	}

	for (int i = size; i < size+n; i++) {
		cin >> tree[i];
	}

	init(size,n);


	int s = m + k;
	int a, b, c;

	for (int i = 0; i < s; i++) {

		cin >> a >> b >> c;

		if (a == 1) {

			update(b,c,size,n);
		}
		else {
			cout << mul(b,c,size) << endl;
		}

	}


	return 0;
}