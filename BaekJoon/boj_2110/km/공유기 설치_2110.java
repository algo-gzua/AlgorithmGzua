import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			String[] s = br.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int C = Integer.parseInt(s[1]);
			
			int[] home = new int[N]; 
			for (int i = 0; i < N; ++i) {
				home[i] = Integer.parseInt(br.readLine());
			}
			
			Arrays.sort(home);
			
			int left = 1;
			int right = 1000000000;
			int result = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				int remainCount = C - 1;
				
				int prev = home[0];
				for (int i = 1; i < N; ++i) {
					if (prev + mid <= home[i]) {
						remainCount--;
						prev = home[i];
						
						if (remainCount == 0) {
							break;
						}
					}
				}
				
				if (remainCount == 0) {
					result = mid;
					left = mid + 1;
				} else {
					right = mid - 1;
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