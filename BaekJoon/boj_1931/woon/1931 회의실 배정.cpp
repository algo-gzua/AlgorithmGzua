#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {

	int start;
	int end;

};

vector<Node> m;
vector<int> max;

void Max_room(int x, int size) {
	int min = m[x].end;
	vector<Node>::iterator iter = m.begin();

	while (iter != m.end()) {
		if (min > iter->start) {
			iter = m.erase(iter);
		}
		else {
			iter++;
		}
	}
}

void Min_found(int size) {


	int x = 0;
	int min = 999999;

	//시작찾기
	for (int i = 0; i < size; i++) {

		// 회의 끝나는 시간이 가장 작을때
		if (m[i].end < min) {
			min = m[i].end;
			x = i;
		}
	}
	// 입력받은 위치의 값을 저장
	max.push_back(x);
	Max_room(x, size);
}

int main() {

	int n;
	Node time;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> time.start >> time.end;
		m.push_back(time);
	}


	while (!m.empty()) {
		
		int size = m.size();
		
		//시작구하기
		Min_found(size);
	}

	int room = max.size();
	cout << room;









	return 0;
}