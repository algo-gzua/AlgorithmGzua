#include<iostream>

using namespace std;

int main(void) {
	int N; scanf("%d", &N);
	int end_n = N;
	int cnt = 0;
	int a, b, c;

	while (1) {
		a = N % 10;
		b = (N / 10) % 10;
		c = (a + b) % 10;

		N = a * 10 + c;

		cnt++;
		if (N == end_n) {
			break;
		}
	}


	getchar();
}