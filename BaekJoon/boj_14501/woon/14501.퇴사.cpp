#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct NODE {
	int t;
	int p;
};

int main() {

	int result[16] = { 0, };
	NODE node;
	vector<NODE> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> node.t >> node.p;
		v.push_back(node);
	}

	int x;
	for (int i = n-1; i >= 0; i -- ) {

		x = i + v[i].t;
		
		if (x > n) {
			// 그 전에 가격 그대로 가져오기
			result[i] = result[i + 1];

		}
		else {
			result[i] = max(result[i + 1], result[x] + v[i].p);
		}
	}

	cout << result[0] << endl;


	return 0;
}