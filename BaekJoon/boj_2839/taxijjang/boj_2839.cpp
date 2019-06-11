#include<iostream>

int main(void) {
	int N; scanf("%d", &N);
	int cnt = 0;
	while (1) {
		if (N % 5 == 0) {
			printf("%d", (N / 5) + cnt);
			break;
		}
		else if(N <= 0){
			printf("-1");
			break;
		}
		N -= 3; cnt++;
	}
	return 0;
}