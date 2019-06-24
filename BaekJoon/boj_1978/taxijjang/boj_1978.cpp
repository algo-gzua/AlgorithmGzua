#include<iostream>

bool arr[1001] = { true,true, };

int main(void) {
	for (int i = 2; i < 1001; i++) {
		for (int j = i; j*i < 1001; j++) {
			if (arr[j*i] != true) arr[j*i] = true;
		}
	}
	int N; scanf("%d", &N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int n; scanf("%d", &n);
		if (arr[n] == false) cnt++;
	}

	printf("%d\n", cnt);
}