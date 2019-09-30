#include <iostream>
using namespace std;


int quick[1001];

void sort(int x, int y) {

	if (x >= y) {
		return;
	}

	int pivot = quick[(x + y) / 2];
	int left = x;
	int right = y;

	while (left <= right) {

		while (quick[left] < pivot) {
			left++;
		}
		while (quick[right] > pivot) {
			right--;
		}

		if (left <= right) {
			int tmp = quick[left];
			quick[left] = quick[right];
			quick[right] = tmp;
			left++;
			right--;
		}
	}
	sort(x, right);
	sort(left, y);
}
int main() {

	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> quick[i];
	}

	sort(0, n - 1);


	for (int i = 0; i < n; i++) {
		cout << quick[i] << endl;
	}
	return 0;
}