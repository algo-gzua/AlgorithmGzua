#include <iostream>
#include <string>
#define mod 1000000000
using namespace std;

int d[201][201];
int main() {

	int n, k;
	cin >> n >> k;


	// 1로 초기화
	for (int i = 0; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			d[i][j] = 1;
		}
	}

	if (k == 1) {
		cout << 1;
	}
	else if (k == 2) {
		cout << (n + 1) << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 3; j <= k; j++) {

				d[i][j] = d[i][j - 1] + d[i - 1][j];
				d[i][j] = d[i][j] % mod;
			}
		}
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			sum = (sum + d[i][k]) % mod;
		}
		cout << sum;

	}

	system("pause");
	return 0;
}