#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> board;
string map[31][31];
bool check[31][31];

void find(int i, int j) {
	//체크배열 true로 바꿔주기 조건에해당하면
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
	//0. 입력 받은 board 배열을 다시 정리 

	int k = 0;
	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = board[k++];
		}
	}

	//4. 위에 반복
	//1~3을 반복

	bool flag = true;
	while (true) {

		// 1. 2x2 행렬 찾기
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				find(i, j);
			}
		}

		int count = 0;
		//2. 2x2 찾으면 없애기
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// cehck 가 true 라면 map[i][j]를 z로 변경		
				if (check[i][j] == true) {
					map[i][j] = "";
					count++;
				}
			}
		}

		// 반복 종료하는 시점
		if (count == 0) {
			flag = false;
			break;
		}

		//3. 없어진 빈공간을 위에서 채우기
		// 한줄을 다 검사하기 , true -> false로 초기화

		for (int i = (m - 1); i > 0; i--) {
			for (int j = 0; j < n; j++) {
				int start = i;
				if (map[i][j] != "") {
					continue;
				}
				else {
					int end = start;

					while (true) {
						//check 배열 바꿔주기
						if (check[start][j] == true) {
							check[start][j] = false;
						}
						start--;

						if (map[start][j] != "" || start < 0) {
							break;
						}
					}

					//블록이 있으면 시작한 점에 끝점을 넣어줌
					//빈칸으로 바꿔줌
					if (map[start][j] != "") {
						map[end][j] = map[start][j];
						map[start][j] = "";

					}
					// 빈칸이라 map에 끝에 도착했다면
					else if (start + 1 == 0) {
						map[end][j] = "";
					}

				}
			}
		}
	}

	//5. 빈칸 검색해서 answer로 반환
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