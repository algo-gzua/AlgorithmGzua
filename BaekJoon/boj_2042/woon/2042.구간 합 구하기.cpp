#include <iostream>
using namespace std;


long long t[2100000];
void init(int size) {


	while (size > 1) {
		for (int i = size; i <= (size * 2) - 1; i = i + 2) {

			t[i / 2] = t[i] + t[i + 1];

		}
		size = size / 2;
	}
}
void update(int b, int c, int size) {
	long long tmp = size + b - 1;
	t[tmp] = c;

	while (tmp > 1) {
		if (tmp % 2 != 0) {
			t[tmp / 2] = t[tmp] + t[tmp - 1];
		}
		else {
			t[tmp / 2] = t[tmp] + t[tmp + 1];
		}
		tmp = tmp / 2;
	}
}

long long sum(long long b, long long c, int size) {

	int left = size + b - 1;
	int right = size + c - 1;

	long long result = 0;
	while (left < right) {

		if (left % 2 != 0) {
			result = result + t[left];
			left++;
		}
		if (right % 2 == 0) {
			result = result + t[right];
			right--;
		}

		left = left / 2;
		right = right / 2;
	}

	if (left == right) {
		result = result + t[left];
	}
	return result;
}

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int size = 1;
	while (size < n) {
		size = size * 2;
	}

	
	for (int i = size; i < size + n; i++) {
		cin >> t[i];
	}

	init(size);


	long long a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			update(b, c, size);
			break;
		case 2:
			cout << sum(b, c, size) << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}