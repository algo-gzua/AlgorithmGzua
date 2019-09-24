#include<iostream>
#include<queue>

using namespace std;

int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };

char arr[13][7];
char tmp[13][7];
bool visited[13][7];
int cnt = 0;
void input() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}
}
void print() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

bool check(int h_x, int h_y) {
	if (visited[h_x][h_y] == true)
		return false;

	int c = arr[h_x][h_y];

	queue<pair<int, int>> m;
	queue<pair<int, int>> q;

	visited[h_x][h_y] = true;
	q.push({ h_x,h_y });
	m.push({ h_x,h_y });
	while (!q.empty()) {
		int h_x = q.front().first;
		int h_y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int n_x = h_x + x[i];
			int n_y = h_y + y[i];

			if (c != arr[n_x][n_y])
				continue;
			if (visited[n_x][n_y] == true)
				continue;
			if (n_x < 1 || n_y < 1 || n_x >12 || n_y > 6)
				continue;

			visited[n_x][n_y] = true;
			q.push({ n_x,n_y });
			m.push({ n_x,n_y });

		}
	}

	bool operat = false;

	
	int m_size = m.size();
	if (m_size >= 4) {
		operat = true;
		for (int i = 0; i < m_size; i++) {
			arr[m.front().first][m.front().second] = '.';
			m.pop();
		}
	}

	return operat;
}

void down() {
	for (int j = 1; j <= 6 ; j++) {
		int dot_cnt = 0;
		for (int i = 12; i >= 1; i--) {
			if (arr[i][j] == '.') {
				dot_cnt++;
			}
			else if (arr[i][j] != '.' && dot_cnt!=0) {
				arr[i + dot_cnt][j] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}
}

void fill_v() {
	for (int i = 0; i <= 12; i++) {
		for (int j = 0; j <= 6; j++) {
			visited[i][j] = false;
		}
	}
}

int main(void) {
	input();
	int find_cnt = 0;
	do {
		find_cnt = 0;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				if (arr[i][j] == '.')
					continue;
				if (check(i, j)) {
					find_cnt++;	
				}
			}
		}
		down();
		fill_v();
		//print();
		if(find_cnt != 0)
			cnt++;
	} while (find_cnt != 0);

	cout << cnt;
}