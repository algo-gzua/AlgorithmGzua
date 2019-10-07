import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			String[] s = br.readLine().split(" ");
			
			// 곡의 개수
			int N = Integer.parseInt(s[0]);
			// 시작 볼륨
			int S = Integer.parseInt(s[1]);
			// 최대 볼륨
			int M = Integer.parseInt(s[2]);
			
			int[] arr = new int[N];
			boolean[][] visit = new boolean[N + 1][M + 1];
			
			s = br.readLine().split(" ");
			for (int i = 0; i < N; ++i) {
				arr[i] = Integer.parseInt(s[i]);
			}
			
			visit[0][S] = true;
			
			for (int i = 1; i <= N; ++i) {
				for (int j = 0; j <= M; ++j) {
					if (visit[i - 1][j]) {
						if (j - arr[i - 1] >= 0) {
							visit[i][j - arr[i - 1]] = true;
						}
						
						if (j + arr[i - 1] <= M) {
							visit[i][j + arr[i - 1]] = true;
						}
					}
				}
			}
			
			int result = -1;
			for (int i = 0; i <= M; ++i) {
				if (visit[N][i]) {
					result = i;
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