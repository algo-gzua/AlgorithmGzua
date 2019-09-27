import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int N = Integer.parseInt(br.readLine());
			
			for (int n = 0; n < N; ++n) {
				String s = br.readLine();
				
				int result = 0;
				int currPoint = 0;
				for (int i = 0; i < s.length(); ++i) {
					if (s.charAt(i) == 'O') {
						result += ++currPoint;
					} else {
						currPoint = 0;
					}
				}
				
				System.out.println(result);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Main().solve();
	}
}