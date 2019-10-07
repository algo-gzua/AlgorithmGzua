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
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			int[] arr = new int[N];
			
			for (int i = 0; i < N; ++i) {
				arr[i] = Integer.parseInt(br.readLine());
			}
			
			Arrays.sort(arr);
			
			long result = 0;
			long left = arr[0];
			long right = (long)arr[N - 1] * M;
			
			while (left <= right) {
				long mid = (left + right) / 2;
				long temp = 0;
				
				for (int i = 0; i < N; ++i) {
					temp += mid / arr[i];
				}
				
				if (temp >= M) {
					result = mid;
					right = mid - 1;
				} else {
					left = mid + 1;
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