#include<iostream>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int num = i;
		bool judge = true;
		while (num != 0) {
			if ((num % 10) % 3 == 0 && num %10 !=0) {
				printf("%c", '-');		
				judge = false;
			}
			num /= 10;
		}
		if (judge) {
			printf("%d ", i);
		}
		else {
			printf(" ");
		}
	}
}