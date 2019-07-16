#include<iostream>
#define SIZE 1010

typedef struct Data {
	int time;
	int pay;
}Data;

Data arr[SIZE] ;
int dp[SIZE];
int m_pay = 0;
void dfs(int h_d, int sum, int N) {
	if (h_d + arr[h_d].time >= N + 1) {
		if (h_d + arr[h_d].time == N + 1)
			sum += arr[h_d].pay;
		m_pay = m_pay < sum ? sum : m_pay;
		return;
	}
	sum += arr[h_d].pay;
	int len = h_d + arr[h_d].time;
	for (int i = h_d + 1; i <= N; i++) {		
		if (i < len) continue;
		else {
			dfs(i, sum, N);
		}
	}
}
int main(void) {
	int N; scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i].time, &arr[i].pay);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, 0, N);
	}

	printf("%d", m_pay);
}