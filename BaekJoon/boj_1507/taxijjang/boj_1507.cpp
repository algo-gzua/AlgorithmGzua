#include<iostream>
#include<algorithm>
#define SIZE 21

using namespace std;

const int INF = 2e9;


int main(void) {
	int N; scanf("%d", &N);

	int arr[SIZE][SIZE];
	int dis[SIZE][SIZE];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			dis[i][j] = arr[i][j];
		}
	}

	int bridge = 0;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == k || j == k)
					continue;
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					printf("-1");
					return 0;
				}
				if (dis[i][j] == dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					arr[i][j] = 0;
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			res += arr[i][j];
		}
	}

	printf("%d", res);
	return 0;
}