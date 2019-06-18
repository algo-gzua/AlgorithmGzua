#include<iostream>
#define SIZE1 10001
#define SIZE2 101
using namespace std;

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		bool arr[SIZE1] = { false, };
		int num[SIZE2] = { 0, };
		arr[0] = true;

		int N; scanf("%d", &N);
		
		int max = 0; 

		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
			max += num[i];
			for (int j = max; j >= 0; j--) {
				if (arr[j] == true) 
					arr[j + num[i]] = true;
			}
		}
		int cnt = 0;
		for (int i = 0; i < SIZE1; i++) {
			if (arr[i] == true) cnt++;
		}

		printf("#%d %d\n", t, cnt);
	}
}