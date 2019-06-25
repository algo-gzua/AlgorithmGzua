#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {

	int start;
	int end;

};

vector<Node> v;

// 회의실 마감시간이 작은거부터 큰순서대로 정렬
bool compare(const Node& x, const Node& y) {
	if (x.end == y.end) {
		return x.start < y.start;
	}
	else {
		return x.end < y.end;
	}
}


int main() {

	int n;

	Node time;
	vector<Node>::iterator iter = v.begin();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> time.start >> time.end;
		v.push_back(time);
	}

	// 구조체 특정 값을 정렬하는 방법
	sort(v.begin(), v.end(), compare);

	int x = v[0].end;
	
	int count = 0;
	for (int i = 1; i < n; i++) {
		
		if (x > v[i].start) {
			continue;
		}
		else {
			x = v[i].end;
			count = count + 1;
		}
	}
	
	cout << count ;



	return 0;
}