#include<iostream>
#include<algorithm>
#define SIZE 100001

using namespace std;

int arr[SIZE];

void search(int num,int N) {
	int n = num;
	int size = N;
	int left = 0, right = size-1, mid;
	bool judge = false;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == num) {
			judge = true;
		}
		else if (arr[mid] > num) {
			right = mid - 1;
		}
		else if (arr[mid] < num) {
			left = mid + 1;
		}
		if (judge)
			break;
	}
	if (judge)
		printf("1\n");
	else
		printf("0\n");

}
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int num; scanf("%d", &num);
		search(num,N);
	}
	return 0;
}