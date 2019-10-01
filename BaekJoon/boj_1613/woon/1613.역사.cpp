#include <iostream>
#include <algorithm>
#define INF 210000000

using namespace std;

int check[401][401];
void init(int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				check[i][j] = 0;
			}
			else {
				check[i][j] = INF;
			}
		}
	}

}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	init(n);
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;

		check[x][y] = 1;
	}

	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				check[i][j] = min(check[i][j], check[i][k] + check[k][j]);
			}
		}
	}

	int s;
	cin >> s;

	for (int i = 0; i < s; i++) {
		cin >> x >> y;

		if (check[x][y] != 0 && check[x][y] != INF) {
			cout << -1 << '\n';
		}
		else if (check[x][y] == INF && check[y][x] != INF) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}


	return 0;
}