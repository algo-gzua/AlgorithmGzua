#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {

	int t, tc;
	int i, n;
	int high;
	vector<int> v;
	deque<int> dq;

	cin >> t;
	for (tc = 1; tc <= t; tc++) {

		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> high;
			v.push_back(high);
		}

		sort(v.begin(), v.end());
		int size = v.size();

		for (i = 0; i < size; i++) {
			if (i % 2 == 0) {
				dq.push_front(v[i]);
			}
			else {
				dq.push_back(v[i]);
			}
		}

		/* deque 출력
		for (i = 0; i < size; i++) {
			cout << dq[i];
		}
		cout << endl;*/

		int max = 0;
		for (i = 1; i < size; i++) {
			if (max < abs(dq[i] - dq[i - 1])) {
				max = abs(dq[i] - dq[i - 1]);
			}
		}

		cout << "#" << t <<" "<< max << endl; 

		//메모리 해제
		vector<int>().swap(v);
		deque<int>().swap(dq);
		

	}
	return 0;
}