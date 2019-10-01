#include<iostream>
#include<algorithm>
#include<queue>

#define SIZE 410
#define INF 1e9
using namespace std;

int arr1[SIZE][SIZE];
int arr2[SIZE][SIZE];

void fill_arr(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) continue;
			arr1[i][j] = INF;
			arr2[i][j] = INF;
		}
	}
}

queue<pair<int, int>> q;

int main(void) {
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;

	fill_arr(n);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;

		arr1[x][y] = 1;
		arr2[y][x] = 1;
	}

	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr1[i][j] = min(arr1[i][j], arr1[i][k] + arr1[k][j]);
				arr2[i][j] = min(arr2[i][j], arr2[i][k] + arr2[k][j]);
			}
		}
	}

	int question; cin >> question;
	for (int i = 0; i < question; i++) {
		int h_x, h_y; cin >> h_x >> h_y;
		bool minus = false, plus = false, zero = false;

		if (arr1[h_x][h_y] < INF && arr1[h_x][h_y] > 0) {
			minus = true;
			zero = !zero;
		}
		if (arr2[h_x][h_y] < INF && arr2[h_x][h_y] > 0) {
			plus = true;
			zero = !zero;
		}

		if (zero == false) 
			printf("%d\n", 0);
		else if (minus == true && plus == false)
			printf("%d\n", -1);
		else if (minus == false && plus == true)
			printf("%d\n", 1);
	}
}