import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			String[] s = br.readLine().split(" ");
			
			int N = Integer.parseInt(s[0]);
			int K = Integer.parseInt(s[1]);
			int[][] arr = new int[N + 1][N + 1];
			final int INF = 200000000;
			
			for (int i = 1; i <= N; ++i) {
				Arrays.fill(arr[i], INF);
			}
			
			for (int i = 1; i <= K; ++i) {
				s = br.readLine().split(" ");
				arr[Integer.parseInt(s[0])][Integer.parseInt(s[1])] = 1;
			}
			
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					if (i == j) {
						arr[i][j] = 0;
					}
				}
			}
			
			for (int k = 1; k <= N; ++k) {
				for (int i = 1; i <= N; ++i) {
					for (int j = 1; j <= N; ++j) {
						if (arr[i][j] > arr[i][k] + arr[k][j]) {
							arr[i][j] = arr[i][k] + arr[k][j];
						}
					}
				}
			}
			
			int S = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < S; ++i) {
				s = br.readLine().split(" ");
				int a = Integer.parseInt(s[0]);
				int b = Integer.parseInt(s[1]);
				
				if (arr[a][b] != INF) {
					System.out.println("-1");
				} else if (arr[b][a] != INF) {
					System.out.println("1");
				} else {
					System.out.println("0");
				}
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Main().solve();
	}
}