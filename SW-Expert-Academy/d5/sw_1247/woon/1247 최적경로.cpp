#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


struct Point {
	int x;
	int y;
	bool flag = 0;
};

int distance(int x1, int y1, int x2, int y2) {
	return  abs(x1 - x2) + abs(y1 - y2);
}

int main() {

	int i, n, tc;

	vector<Point> v;
	Point p;

	for (tc = 1; tc <= 10; tc++) {
		//고객 수
		cin >> n;

		for (i = 0; i < n + 2; i++) {
			cin >> p.x >> p.y;
			v.push_back(p);
		}


		vector<int> result;
		int cur_x = 0, cur_y = 0;
		int min = 1000;
		int check[13];
		int d = 0;

		fill(check, check + 13, 1000);

		// 회사에서 가까운 고객 찾기
		for (i = 2; i < n + 2; i++) {

			d = distance(v[0].x, v[0].y, v[i].x, v[i].y);
			check[i] = d;
		}
		for (i = 0; i < 13; i++) {
			if (min > check[i]) {
				min = check[i];

				cur_x = i;
				cur_y = i;

			}
		}
		v[cur_x].flag = 1;
		result.push_back(min);


		int s = 1;
		//고객간에 가까운거리찾기
		while (s < n) {
			min = 1000;
			fill(check, check + 13, 1000);

			for (i = 2; i < n + 2; i++) {
				if (i == cur_x) {
					continue;
				}
				else if (v[i].flag == 1) {
					continue;
				}

				else if (v[i].flag == 0) {
					d = distance(v[cur_x].x, v[cur_y].y, v[i].x, v[i].y);
					check[i] = d;
				}
			}
			for (i = 0; i < 13; i++) {
				if (min > check[i]) {
					min = check[i];


					cur_x = i;
					cur_y = i;

				}
			}
			result.push_back(min);
			v[cur_x].flag = 1;
			s++;
		}

		d = distance(v[cur_x].x, v[cur_y].y, v[1].x, v[1].y);
		result.push_back(d);

		int sum = 0;
		for (i = 0; i < result.size(); i++) {
			sum = sum + result[i];
		}

		cout << "#" << tc << " " << sum << endl;
		vector<int> reclear;
		vector<Point> vclear;

		result.swap(reclear);
		reclear.clear();
		result.clear();

		v.swap(vclear);
		vclear.clear();
		v.clear();
	}
	return 0;
}

