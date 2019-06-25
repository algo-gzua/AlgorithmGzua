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

	//����ã��
	for (int i = 0; i < size; i++) {

		// ȸ�� ������ �ð��� ���� ������
		if (m[i].end < min) {
			min = m[i].end;
			x = i;
		}
	}
	// �Է¹��� ��ġ�� ���� ����
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
		
		//���۱��ϱ�
		Min_found(size);
	}

	int room = max.size();
	cout << room;









	return 0;
}