#include<iostream>
#define SIZE 2000000
using namespace std;

bool arr[SIZE];

void eratos() {
	arr[0] = arr[1] = true;
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; j*i < SIZE; j++) {
			arr[i*j] = true;
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);

	eratos();

	getchar();
	for (int t = 1; t <= T; t++) {
		int D, A, B;
		scanf("%d %d %d", &D, &A, &B);

		int cnt = 0;
		for (int i = A; i <= B; i++) {
			if (arr[i] != true) {
				int num = i;

				while (num != 0) {
					if (num % 10 == D) {
						cnt++;
						break;
					}
					num /= 10;
				}
			}
		}
		printf("#%d %d\n", t, cnt);
	}
}