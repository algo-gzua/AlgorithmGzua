#include <iostream>
#include <algorithm>
using namespace std;


int rope[100001];
int check[100001];
int main() {

	int n;
	cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> rope[i];
	}

	
	sort(rope, rope+n);
	for (i = 0; i < n; i++) {
		check[i] = rope[i] * (n-i);
	}

	int max = 0;
	for (i = 0; i < n; i++) {
		if (max < check[i]) {
			max = check[i];
		}
	}

	cout << max;
	





	return 0;
}