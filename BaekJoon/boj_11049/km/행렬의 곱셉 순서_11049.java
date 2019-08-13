import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int N = Integer.parseInt(br.readLine());
			int[] num = new int[N + 1];
			int[][] dp = new int[N + 1][N + 1];
			final int INF = 999999999;
			
			String[] s = br.readLine().split(" ");
			num[0] = Integer.parseInt(s[0]);
			num[1] = Integer.parseInt(s[1]);
			
			for (int i = 1; i < N; ++i) {
				s = br.readLine().split(" ");
				num[i + 1] = Integer.parseInt(s[1]);
			}
			
			for (int len = 2; len <= N; ++len) {
				for (int start = 1; start <= N - len + 1; ++start) {
					int end = start + len - 1;
					
					if (start == end) {
						// 어쩌피 0이다.
						continue;
					}
					
					dp[start][end] = INF;
					for (int k = start; k < end; ++k) {
						dp[start][end] = Math.min(dp[start][end], dp[start][k] + dp[k + 1][end] + num[start-1] * num[k] * num[end]);
					}
				}
			}
			
			System.out.println(dp[1][N]);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}