#include<iostream>
#include<cmath>
#include<algorithm>
#define SIZE 100010
using namespace std;

int arr[SIZE] = { 0, 1, 2, 3 , };

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		int sq = sqrt(i);
		if (sq*sq == i) {
			arr[i] = 1;
			continue;
		}
		arr[i] = i;
		for (int j = 1; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	printf("%d", arr[N]);
}