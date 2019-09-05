
public class Solution {
	public int solution(int m, int n, String[] board) {
		int answer = 0;
		char[][] arr = new char[m][n];

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				arr[i][j] = board[i].charAt(j);
			}
		}
		
		boolean flag = true;
		while (flag) {
			flag = false;
			boolean[][] check = new boolean[m][n];
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					char curr = arr[i][j];
					if (curr != '-') {
						if (i + 1 < m && j + 1 < n) {
							if (arr[i][j] == arr[i][j + 1] &&
								arr[i][j] == arr[i + 1][j] &&
								arr[i][j] == arr[i + 1][j + 1]) {
								check[i][j] = true;
								check[i][j + 1] = true;
								check[i + 1][j] = true;
								check[i + 1][j + 1] = true;
								flag = true;
							}
						}
					}
				}
			}
			
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (check[i][j] && arr[i][j] != '-') {
						arr[i][j] = '-';
						answer++;
					}
				}
			}
			
			// 블록 내리기
			for (int i = m - 1; i >= 0; --i) {
				for (int j = n - 1; j >= 0; --j) {
					if (arr[i][j] == '-') {
						for (int k = i; k >= 0; --k) {
							if (arr[k][j] != '-') {
								arr[i][j] = arr[k][j];
								arr[k][j] = '-';
								break;
							}
						}
					}
				}
			}
		}
		
		return answer;
	  }
	
	public static void main(String[] args) {
		int m = 6;
		int n = 6;
		String[] board = {"TTTANT", "RRFACC", "RRRFCC",
				"TRRRAA", "TTMMMF", "TMMTTJ"};
		
		System.out.println(new Solution().solution(m, n, board));
	}
}
