#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 5
#define MAX_COMBI 500000
using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool visited[SIZE*SIZE];
bool s_check[SIZE*SIZE];

vector<int> ind;

void fill_v() {
	for (int i = 0; i < SIZE*SIZE; i++) {
		visited[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < SIZE * SIZE; i++) {
		char c; cin >> c;
		s_check[i] = c == 'S' ? true : false;
	}

	ind.assign(7, 1);
	for (int i = 0; i < 25 - 7; i++) {
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());

	int res = 0;
	do {
		vector<int> combi;
		fill_v();
		int y_cnt = 0, s_cnt = 0;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				combi.push_back(i);
			}
		}

		queue<int> q;
		q.push(combi[0]);

		while (!q.empty()) {
			int h_x = q.front() / SIZE;
			int h_y = q.front() % SIZE;
			q.pop();

			if (s_check[h_x*SIZE + h_y]) s_cnt++;
			else y_cnt++;

			visited[h_x * SIZE + h_y] = true;

			for (int i = 0; i < 4; i++) {
				int n_x = h_x + dx[i];
				int n_y = h_y + dy[i];

				if (n_x < 0 || n_y < 0 || n_x >= SIZE || n_y >= SIZE)
					continue;

				if (visited[n_x * 5 + n_y] == true)
					continue;

				for (auto it = combi.begin(); it != combi.end(); it++) {
					if (*it == n_x * 5 + n_y) {
						visited[*it] = true;
						q.push(*it);
					}
				}
			}
		}


		if (y_cnt + s_cnt == 7 && s_cnt >= 4) {
			res++;
		}
	} while (next_permutation(ind.begin(), ind.end()));
	cout << res;
	getchar();
}
