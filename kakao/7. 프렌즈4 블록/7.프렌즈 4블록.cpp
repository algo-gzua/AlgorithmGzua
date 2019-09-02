#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> board;
string map[31][31];
bool check[31][31];

void find(int i, int j) {
	//üũ�迭 true�� �ٲ��ֱ� ���ǿ��ش��ϸ�
	if (map[i][j] != "") {
		if (map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1]) {
			check[i][j] = true;
			check[i + 1][j] = true;
			check[i][j + 1] = true;
			check[i + 1][j + 1] = true;
		}
	}
}

int solution(int m, int n, vector<string> board) {

	
	int answer = 0;
	//0. �Է� ���� board �迭�� �ٽ� ���� 

	int k = 0;
	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = board[k++];
		}
	}

	//4. ���� �ݺ�
	//1~3�� �ݺ�

	bool flag = true;
	while (true) {

		// 1. 2x2 ��� ã��
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				find(i, j);
			}
		}

		int count = 0;
		//2. 2x2 ã���� ���ֱ�
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// cehck �� true ��� map[i][j]�� z�� ����		
				if (check[i][j] == true) {
					map[i][j] = "";
					count++;
				}
			}
		}

		// �ݺ� �����ϴ� ����
		if (count == 0) {
			flag = false;
			break;
		}

		//3. ������ ������� ������ ä���
		// ������ �� �˻��ϱ� , true -> false�� �ʱ�ȭ

		for (int i = (m - 1); i > 0; i--) {
			for (int j = 0; j < n; j++) {
				int start = i;
				if (map[i][j] != "") {
					continue;
				}
				else {
					int end = start;

					while (true) {
						//check �迭 �ٲ��ֱ�
						if (check[start][j] == true) {
							check[start][j] = false;
						}
						start--;

						if (map[start][j] != "" || start < 0) {
							break;
						}
					}

					//����� ������ ������ ���� ������ �־���
					//��ĭ���� �ٲ���
					if (map[start][j] != "") {
						map[end][j] = map[start][j];
						map[start][j] = "";

					}
					// ��ĭ�̶� map�� ���� �����ߴٸ�
					else if (start + 1 == 0) {
						map[end][j] = "";
					}

				}
			}
		}
	}

	//5. ��ĭ �˻��ؼ� answer�� ��ȯ
	int result = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == "") {
				result = result + 1;
			}
		}
	}

	answer = result;
	return answer;
}

int main() {


	int m, n;
	cin >> m >> n;

	string s;
	char c;
	for (int i = 0; i < m*n; i++) {
		cin >> c;
		s = c;
		board.push_back(s);
	}

	cout << solution(m,n,board);
	return 0;
}