#include<iostream>
#include<vector>
#include<cmath>
#define SUM 32768
#define SIZE 110
#define INF 10000
using namespace std;

typedef struct Data {
	int x, y;
}Data;

Data d[SIZE];
int n;
int dis[SIZE][SIZE];

void init_dis() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			dis[i][j] = INF;
		}
	}
}

int man(Data d1, Data d2) {
	int diss = abs(d1.x - d2.x) + abs(d1.y - d2.y);
	return diss;
}
int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		n += 2;

		for (int i = 0; i < n; i++) {
			cin >> d[i].x >> d[i].y;
			d[i].x += SUM; d[i].y += SUM;
		}

		init_dis();

		for (int i = 0; i < n; i++) {
			Data d_i = d[i];
			for (int j = 0; j < n; j++) {
				Data d_j = d[j];
				if (i == j)
					continue;

				if (man(d_i,d_j) <= 1000)
					dis[i][j] = 1;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}

		if (dis[0][n - 1] > 0 && dis[0][n - 1] < INF)
			cout << "happy";
		else
			cout << "sad";
		cout << "\n";
	}
}