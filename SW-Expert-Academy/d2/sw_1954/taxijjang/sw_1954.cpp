#include<iostream>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int arr[11][11] = { 0 };
		int x = 0, y = -1, turn = 1;
		int num,n=1;
		scanf("%d", &num);

		int tmp = num;
		while (tmp > 0) {
			for (int i = 0; i < tmp; i++) {
				y += turn;
				arr[x][y] = n;
				n++;
			}

			tmp -= 1;

			for (int i = 0; i < tmp; i++) {
				x += turn;
				arr[x][y] = n;
				n++;
			}
			turn *= -1;
		}

		printf("#%d\n", t);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
}