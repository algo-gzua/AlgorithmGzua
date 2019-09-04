#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool check[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (true) {

		//2*2 find
		int v = 0;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {

				if (board[i][j] != ' ') {
					if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
						check[i][j] = true;
						check[i][j + 1] = true;
						check[i + 1][j] = true;
						check[i + 1][j + 1] = true;
						v++;
					}
				}
			}
		}

		if (v == 0) {
			break;
		}
		//2*2 erase

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == true) {
					board[i][j] = ' ';
				}
			}
		}

		//down πÿø°º≠ ∫Œ≈Õ ≈Ωªˆ

		for (int j = 0; j < n; j++) {
			int count = 0;
			for (int i = m - 1; i >= 0; i--) {

				if (board[i][j] == ' ') {
					count++;
					continue;
				}
				else {
					if (count == 0) {
						continue;
					}
					board[i + count][j] = board[i][j];
					board[i][j] = ' ';
				}
			}
		}

		//checkπËø≠ ¥ŸΩ√ √ ±‚»≠
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
	}

	// ∫Ûƒ≠ ∞πºˆ ±∏«œ±‚
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == ' ') {
				answer = answer + 1;
			}
		}
	}
	return answer;
}

int main() {

	int m = 6;
	int n = 6;
	vector<string> v;
	//v.push_back("CCBDE");
	//v.push_back("AAADE");
	//v.push_back("AAABF");
	//v.push_back("CCBBF");

	v.push_back("TTTANT");
	v.push_back("RRFACC");
	v.push_back("RRRFCC");
	v.push_back("TRRRAA");
	v.push_back("TTMMMF");
	v.push_back("TMMTTJ");

	//v.push_back("TTTTTT");
	//v.push_back("TTTTTT");
	//v.push_back("TTTTTT");
	//v.push_back("TTTTTT");
	//v.push_back("TTTTTT");
	//v.push_back("TTTTTT");

	cout << solution(m, n, v);
	return 0;
}