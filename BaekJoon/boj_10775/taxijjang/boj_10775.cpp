#include<iostream>
#define SIZE 100010
using namespace std;

int parrent[SIZE];

void init() {
	for (int i = 1; i < SIZE; i++) {
		parrent[i] = i;
	}
}
int find(int a) {
	if (parrent[a] == a)
		return a;
	else
		return parrent[a] = find(parrent[a]);
}

void uni(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	parrent[a] = b;
}
int main(void) {
	ios::sync_with_stdio(false);

	init();

	int G, P; cin >> G >> P;
	int res = 0;
	for (int i = 1; i <= P; i++) {
		int p; cin >> p;

		int d = find(p);

		if (d != 0) {
			uni(d, d - 1);
			res++;
		}
		else
			break;
	}

	cout << res;
}