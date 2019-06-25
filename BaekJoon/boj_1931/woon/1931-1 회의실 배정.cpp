#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {

	int start;
	int end;

};

vector<Node> v;

// ȸ�ǽ� �����ð��� �����ź��� ū������� ����
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

	// ����ü Ư�� ���� �����ϴ� ���
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