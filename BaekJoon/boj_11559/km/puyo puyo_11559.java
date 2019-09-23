import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	char[][] board;
	boolean[][] visit;
	int[][] direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int sameCount;
	
	private void dfs(int y, int x, char curr) {
		if (board[y][x] == curr) {
			for (int i = 0; i < 4; ++i) {
				int newY = y + direct[i][0];
				int newX = x + direct[i][1];
				
				if (newY >= 12 || newY < 0 || newX >= 6 || newX < 0) {
					continue;
				}
				
				if (visit[newY][newX] || board[newY][newX] != curr) {
					continue;
				}
				
				visit[newY][newX] = true;
				sameCount++;
				dfs(newY, newX, curr);
			}
		}
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			board = new char[12][6];
			visit = new boolean[12][6];
			
			String s;
			for (int i = 0; i < 12; ++i) {
				s = br.readLine();
				
				for (int j = 0; j < 6; ++j) {
					board[i][j] = s.charAt(j);
				}
			}
			
			boolean flag = true;
			int result = 0;
			while (flag) {
				flag = false;
				
				for (int i = 0; i < 12; ++i) {
					for (int j = 0; j < 6; ++j) {
						if (board[i][j] != '.') {
							sameCount = 0;
							for (int k = 0; k < 12; ++k) {
								Arrays.fill(visit[k], false);
							}
							
							visit[i][j] = true;
							sameCount++;
							dfs(i, j, board[i][j]);
							
							if (sameCount >= 4) {
								for (int a = 0; a < 12; ++a) {
									for (int b = 0; b < 6; ++b) {
										if (visit[a][b]) {
											board[a][b] = '.';
										}
									}
								}
								
								flag = true;
							}
						}
					}
				}

				if (flag) {
					// 배열 땡기기
					for (int a = 11; a >= 0; --a) {
						for (int b = 5; b >= 0; --b) {
							if (board[a][b] == '.') {
								int height = a;
								for (int k = a - 1; k >= 0; --k) {
									if (board[k][b] != '.') {
										height = k;
										break;
									}
								}
								
								char temp = board[a][b];
								board[a][b] = board[height][b];
								board[height][b] = temp;
							}
						}
					}
					
					result++;
				}
			}
			
			System.out.println(result);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}