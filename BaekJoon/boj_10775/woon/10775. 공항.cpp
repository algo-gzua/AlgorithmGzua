#include <iostream>
#include <vector>
using namespace std;


int parent[100001];
void init(int g) {
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
}

int find(int x) {

	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}

}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;

}

int main() {

	int g;
	cin >> g;

	init(g);
	int p;
	cin >> p;


	int result = 0;
	int t;
	for (int i = 1; i <= p; i++) {
		int x;
		cin >> x;

		t = find(x);
		if (t == 0) {
			break;
		}
		else {
			Union(t, t - 1);
			result = result + 1;
		}		
	}


	cout << result;
	return 0;
}