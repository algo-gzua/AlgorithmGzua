#include<iostream>
#define SIZE 101

bool arr[SIZE];

using namespace std;

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		fill(arr, arr + SIZE, true);
		int n; scanf("%d", &n);

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j *i <= n; j++) {
				if (arr[i*j] == true) {
					arr[i*j] = false;
				}
				else {
					arr[i*j] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] == true) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}