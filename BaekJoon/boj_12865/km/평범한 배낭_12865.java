import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			String[] s = br.readLine().split(" ");
			
			int N = Integer.parseInt(s[0]);
			int K = Integer.parseInt(s[1]);
			int[][] dp = new int[N + 1][K + 1];
			
			for (int n = 1; n <= N; ++n) {
				s = br.readLine().split(" ");
				
				int W = Integer.parseInt(s[0]);
				int V = Integer.parseInt(s[1]);
				
				for (int i = 0; i <= K; ++i) {
					if (i - W >= 0) {
						dp[n][i] = Math.max(dp[n-1][i - W] + V, dp[n-1][i]);
					} else {
						dp[n][i] = Math.max(dp[n-1][i], dp[n][i]);
					}
				}
			}
			
			System.out.println(dp[N][K]);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}