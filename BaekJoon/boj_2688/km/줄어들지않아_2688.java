import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			long[][] dp = new long[66][10];
			
			for (int i = 0; i < 10; ++i) {
				dp[1][i] = 1;
			}
			
			for (int i = 2; i < 66; ++i) {
				long sum = 0;
				for (int j = 0; j < 10; ++j) {
					sum += dp[i-1][j];
				}
				
				dp[i][0] = sum;
				for (int j = 1; j < 10; ++j) {
					dp[i][j] = dp[i][j - 1] - dp[i-1][j - 1];
				}
			}
			
			int T = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < T; ++i) {
				int N = Integer.parseInt(br.readLine());
				
				System.out.println(dp[N + 1][0]);
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Main().solve();
	}
}