#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> pos[10];
bool check[1025];

int _pow(int p) {
	
	int value = 1;
	for (int i = 0; i < p; i++) {
		value = value * 2;
	}

	return value;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;

	int size = 1;
	int c = 0;
	while (true) {
		if (c == k) {
			break;
		}

		size = size * 2;
		c++;
	}

	for (int i = 0; i < size - 1; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}


	int count = 0;
	int level = k;
	for (int i = 0; i < size - 1; i++) {
		
		if (check[i] == false) {
			count++;
			int now = i;
			int dis = _pow(count);

			while (true) {

				if (now > size-1) {
					break;
				}
				check[now] = true;
				pos[level - 1].push_back(v[now]);
				now = now + dis;
			}
			level--;
		}
	}

	for (int i = 0; i < k; i++) {
		int len = pos[i].size();
		for (int j = 0; j < len; j++) {
			cout << pos[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}