import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
			String[] s = br.readLine().split(" ");
			StringBuilder sb = new StringBuilder();
			
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			int x = Integer.parseInt(s[2]);
			int y = Integer.parseInt(s[3]);
			int K = Integer.parseInt(s[4]);
			
			int[][] arr = new int[N][M];
			int[][] dice = new int[4][3];
			
			// init map
			for (int i = 0; i < N; ++i) {
				s = br.readLine().split(" ");
				for (int j = 0; j < M; ++j) {
					arr[i][j] = Integer.parseInt(s[j]);
				}
			}
			
			s = br.readLine().split(" ");
			
			for (int i = 0; i < K; ++i) {
				int flag = Integer.parseInt(s[i]);
				int temp = 0;
				
				switch(flag) {
					// 동
					case 1:
						if (y + 1 < M) {
							temp = dice[1][0];
							dice[1][0] = dice[1][1];
							dice[1][1] = dice[1][2];
							dice[1][2] = dice[3][1];
							dice[3][1] = temp;
							y++;
							if (arr[x][y] == 0) {
								arr[x][y] = dice[1][1];
							} else {
								dice[1][1] = arr[x][y];
								arr[x][y] = 0;
							}
							sb.append(dice[3][1]).append("\n");
						}
						break;
					// 서
					case 2:
						if (y - 1 >= 0) {
							temp = dice[1][2];
							dice[1][2] = dice[1][1];
							dice[1][1] = dice[1][0];
							dice[1][0] = dice[3][1];
							dice[3][1] = temp;
							y--;
							if (arr[x][y] == 0) {
								arr[x][y] = dice[1][1];
							} else {
								dice[1][1] = arr[x][y];
								arr[x][y] = 0;
							}
							sb.append(dice[3][1]).append("\n");
						}
						break;
					// 북
					case 3:
						if (x - 1 >= 0) {
							temp = dice[3][1];
							dice[3][1] = dice[2][1];
							dice[2][1] = dice[1][1];
							dice[1][1] = dice[0][1];
							dice[0][1] = temp;
							x--;
							if (arr[x][y] == 0) {
								arr[x][y] = dice[1][1];
							} else {
								dice[1][1] = arr[x][y];
								arr[x][y] = 0;
							}
							sb.append(dice[3][1]).append("\n");
						}
						break;
					// 남
					case 4:
						if (x + 1 < N) {
							temp = dice[0][1];
							dice[0][1] = dice[1][1];
							dice[1][1] = dice[2][1];
							dice[2][1] = dice[3][1];
							dice[3][1] = temp;
							x++;
							if (arr[x][y] == 0) {
								arr[x][y] = dice[1][1];
							} else {
								dice[1][1] = arr[x][y];
								arr[x][y] = 0;
							}
							sb.append(dice[3][1]).append("\n");
						}
						break;
					default:
						System.out.println("일어날 일 없음");
						break;
				}
			}
			
			bw.write(sb.toString());
			bw.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}
