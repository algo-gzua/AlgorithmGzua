#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int num[1000001];

int main() {

	int n;
	cin >> n;

	num[1] = 1;
	num[2] = 2;
	num[3] = 3;


	for (int i = 4; i <= n; i++) {

		num[i] = num[i - 1] + 1;

		int x = sqrt(i);
		for (int j = x; j>=1; j--) { 
			num[i] = min(num[i],num[i - (j*j) ]+1);
		}
	}




	cout << num[n];



	return 0;
}