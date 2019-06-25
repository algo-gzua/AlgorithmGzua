#include<iostream>
#include<algorithm>
#define SIZE 1010

using namespace std;

int arr[SIZE] = { -1 , };
int d[SIZE];

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 1; i <= N; i++)scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if ((arr[i] > arr[j]) && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	sort(d, d + N+1);
	//printf("%d\n", );
}