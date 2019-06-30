#include<iostream>
#define SIZE 1010

int arr[SIZE];
int dp[SIZE];

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	int m_num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				m_num = m_num < dp[i] ? dp[i] : m_num;
			}
		}
	}
	printf("%d", m_num);
}