#include <iostream>
#include <vector>
using namespace std;

typedef struct NODE {
	int x;
	int y;
}node;

char map[12][6];
void init() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

}

bool visited[12][6];
vector<node> v;
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

void check(int x, int y) {


	for (int i = 0; i < 4; i++) {
		int n_x = x + dir_x[i];
		int n_y = y + dir_y[i];

		if (n_x >= 0 && n_x < 12 && n_y >= 0 && n_y < 6 && !visited[n_x][n_y]) {

			if (map[x][y] == map[n_x][n_y]) {
				visited[n_x][n_y] = true;
				v.push_back({ n_x,n_y });
				check(n_x, n_y);
			}
		}
	}
}

bool flag = false;
void change(int size) {

	int a;
	int b;
	for (int i = size-1; i >= 0; i--) {

		a = v[i].x;
		b = v[i].y;

		map[a][b] = '.';

		v.pop_back();
	}
	// 변화감지
	flag = true;
}

void down() {

	for (int j = 0; j < 6; j++) {
		int zero = 0;
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] == '.') {
				zero++;
			}
			else {
				if (zero != 0) {
					map[i + zero][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	}
}

int main() {

	init();
	int down_count = 0;
	int result = 0;
	while (true) {

		flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {

				if (!visited[i][j]) {
					if (map[i][j] == '.') {
						visited[i][j] = true;
						continue;
					}
					else {
						v.push_back({ i,j });
						visited[i][j] = true;
						check(i, j);

						// 4개이하일떄
						int size = v.size();
						if (size < 4) {
							for (int i = 0; i < size; i++) {
								v.pop_back();
							}
						}
						else {
							change(size);
						}
					}
				}
			}
		}

		if (flag == false) {
			break;
		}

		down();
		down_count++;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visited[i][j] = false;
			}
		}
	}

	result = down_count;
	cout << result;
	return 0;
}