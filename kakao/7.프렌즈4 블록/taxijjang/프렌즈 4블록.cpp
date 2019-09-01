#include <string>
#include <vector>
#include<iostream>

using namespace std;

int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,1,0 };
bool visited[35][35];
bool check;

//2x2 윈도우 검사
void window(int x ,int y, vector<string> board) {
	char h_s = board[x][y];
	if (h_s == '0')
		return;
	bool toggle = false;

	for (int i = 0; i < 4; i++) {
		char n_s = board[x + dx[i]][y + dy[i]];
		if (n_s != h_s) {
			toggle = true;
			return;
		}
	}

	if (!toggle) {
		check = true;
		for (int i = 0; i < 4; i++) {
			visited[x + dx[i]][y + dy[i]] = true;
		}
	}
}

//블록들을 아래로 내림
void board_down(int m , int n, vector<string> &board) {
	int zero_cnt;
	for (int j = 0; j < n; j++) {
		zero_cnt = 0;
		for (int i = m - 1; i >= 0; i--) {
			if (board[i][j] == '0')
				zero_cnt++;
			else {
				board[i + zero_cnt][j] = board[i][j];
				board[i][j] = zero_cnt != 0 ? '0' : board[i][j];
			}
		}
	}
}

//visited랑 동작확인 check 변수 초기화
void init(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
	check = false;
}

//결과값 계산
int res_cnt(int m, int n, vector<string> board) {
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			res += board[i][j] == '0' ? 1 : 0;
		}
	}
	return res;
}

//함수
int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (true) {
		init(m, n);
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				window(i, j, board);
				
			}
		}

		if (check == false)
			break;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == true) {
					board[i][j] = '0';
				}
			}
		}

		
		board_down(m, n, board);
		
	}

	answer = res_cnt(m, n, board);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);

	vector<string>b;
	b.push_back("CCBDE");
	b.push_back("AAADE");
	b.push_back("AAABF");
	b.push_back("CCBBF");
	cout << solution(4, 5, b);
}