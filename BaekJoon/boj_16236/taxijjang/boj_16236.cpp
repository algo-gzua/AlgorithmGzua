#include<iostream>
#include<queue>

#define SIZE 25

using namespace std;

int num[SIZE][SIZE];
int arr[SIZE][SIZE];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };
int N;
bool is_feed;
int visited[SIZE][SIZE];
typedef struct s_Data {
	int x;
	int y;
	int dis;
	int size;
}s_Data;

struct cmp {
	bool operator() (s_Data d1, s_Data d2) {
		if (d1.dis == d2.dis) {
			if (d1.x == d2.x) {
				return d1.y > d2.y;
			}
			return d1.x > d2.x;
		}
		return d1.dis > d2.dis;
	}
};

s_Data isShortpath(int sang_x, int sang_y, int dis, int sang_size) {
	s_Data d; d = { sang_x,sang_y,dis,sang_size };
	queue<s_Data> q;
	priority_queue<s_Data, vector<s_Data>, cmp> pq;
	is_feed = false;
	q.push({ sang_x,sang_y, dis });
	visited[sang_x][sang_y] = true;
	while (!q.empty()) {
		int h_x = q.front().x;
		int h_y = q.front().y;
		int h_dis = q.front().dis;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];
			int n_dis = h_dis + 1;

			if (visited[n_x][n_y] == true)
				continue;
			//예외처리 부분
			if (arr[n_x][n_y] > sang_size)
				continue;
			if (n_x < 1 || n_y <1 || n_x >N || n_y > N)
				continue;

			visited[n_x][n_y] = true;
			//상어가 자신의 크기 보다 작은 먹이를 만났을때
			if (arr[n_x][n_y] < sang_size && arr[n_x][n_y] != 0) {
				s_Data h_feed;
				h_feed.x = n_x; h_feed.y = n_y; h_feed.dis = n_dis; h_feed.size = sang_size;
				pq.push(h_feed);
				is_feed = true;
				continue;
			}
			q.push({ n_x,n_y,n_dis });
		}
	}

	if (pq.empty())
		return d;
	return pq.top();
}

int main(void) {
	int sang_x, sang_y, sang_size = 2;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9)
				sang_x = i, sang_y = j;
		}
	}
	int num_cnt = 0;
	int feed_cnt = 0;
	s_Data d = { sang_x, sang_y, 0 ,sang_size };
	num[sang_x][sang_y] = num_cnt++;
	is_feed = true;
	int cnt = 0;
	arr[sang_x][sang_y] = 0;
	while (is_feed) {
		is_feed = false;
		for (int i = 0; i <SIZE; i++) {
			for (int j = 0; j<SIZE; j++) {
				visited[i][j] = false;
			}
		}
		d = isShortpath(d.x, d.y, d.dis, d.size);

		if (is_feed) {
			num[d.x][d.y] = num_cnt++;
			arr[d.x][d.y] = 0;
			feed_cnt++;
			cnt = d.dis;
			if (feed_cnt == d.size) {
				d.size++;
				feed_cnt = 0;
			}
		}
	}

	printf("%d", cnt);
}