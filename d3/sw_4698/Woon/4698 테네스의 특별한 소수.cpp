#include<iostream>
using namespace std;

int main() {

	int tc, t, i;


	cin >> t;
	for (tc = 0; tc < t; tc++) {

		int a, b, d;
		int count = 0;

		scanf("%d", &d);
		scanf("%d %d", &a, &b);

		// 범위 설정
		for (i = a; i <= b; i++) {
			bool prime = true; 
			if (i == 0 || i == 1) {
				prime = false;
			}

			// 소수판별
			for (int j = 2; j < i; j++) {				
				if (i%j == 0) {
					prime = false;
					break;
				}
			}

			if (prime) {
				if(i % 10 == d) {
					count++;
				}
			}				
		}
		printf("#%d %d\n", tc + 1, count); 
	}
	return 0;
}

