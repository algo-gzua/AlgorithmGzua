#include<iostream>
#include<algorithm>
#define SIZE 100010

using namespace std;

int arr[SIZE];
int d[SIZE];
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);
	int m_cnt = 0;
	for (int i = 0; i < N; i++) {
		m_cnt = max(m_cnt,arr[i] * (N - i));
	}

	printf("%d\n", m_cnt);
}