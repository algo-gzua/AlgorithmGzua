#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 101

using namespace std;

typedef struct data {
	int row;
	int columm;

	bool operator<(data  d) {
		return row < d.row;
	}
}Data;

bool cmp(const Data & d1, const Data &d2) {
	if (d1.row*d1.columm == d2.row*d2.columm)
		return (d1.row < d2.row);
	return (d1.row * d1.columm < d2.row*d2.columm);
}
int arr[SIZE][SIZE];

bool find(int i, int j) {
	if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
		return true;
	}
	return false;
}

int haeng(int i, int j) {
	int cnt = 0;
	while (arr[i][j] != 0) {
		i++;
		cnt++;
	}
	return cnt;
}

int yel(int i, int j) {
	int cnt = 0;
	while (arr[i][j] != 0) {
		j++;
		cnt++;
	}
	return cnt;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		vector<Data> data;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				bool judge = find(i, j);
				if (judge && arr[i][j] != 0) {
					int row = haeng(i, j);
					int columm = yel(i, j);
					Data d; d.row = row; d.columm = columm;
					data.push_back(d);
				}
			}
		}

		sort(data.begin(), data.end(), cmp);

		printf("#%d %d ", t, data.size());
		for (auto it = data.begin(); it != data.end(); it++) {
			printf("%d %d ", it->row, it->columm);
		}
		printf("\n");

		fill(&arr[0][0], &arr[SIZE][SIZE], 0);

	}
}