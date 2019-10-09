#include<iostream>
#include<queue>
#include<vector>
#define SIZE 20010
using namespace std;

vector<int> v[SIZE];
queue<int> q;

bool visited[SIZE];
int total_len[SIZE];

typedef struct Data {
	int num=20010;
	int len=0;
	int cnt=0;
}Data;
int main(void) {
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y); v[y].push_back(x);
	}

	q.push(1);
	visited[1] = true;
	
	Data res;
	while (!q.empty()) {
		int h_x = q.front();
		q.pop();
		for (int i = 0; i < v[h_x].size(); i++) {
			int h_y = v[h_x][i];

			if (visited[h_y] == true)
				continue;

			visited[h_y] = true;
			total_len[h_y] = total_len[h_x] + 1;
			res.len = res.len < total_len[h_y] ? total_len[h_y] : res.len;
			q.push(h_y);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (res.len == total_len[i]) {
			res.cnt++;
			res.num = res.num < i ? res.num : i;
		}
	}

	cout << res.num << " " << res.len << " " << res.cnt;
}