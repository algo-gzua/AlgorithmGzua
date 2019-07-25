#include<iostream>
#include<queue>
#define SIZE 110
using namespace std;

priority_queue<int> arr;
int num[SIZE];
int main(void) {
	int K, N; scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%d", &num[i]);
		arr.push(-num[i]);
	}

	int tmp;
	for (int i = 0; i < N; i++) {
		tmp = arr.top();
		arr.pop();
		for (int j = 0; j < K; j++) {
			arr.push(tmp*num[j]);

			if (tmp % num[j] == 0)
				break;
		}
	}

	printf("%d", -tmp);

	return 0;
}