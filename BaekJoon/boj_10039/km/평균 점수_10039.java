import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;


public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int result = 0;
			for (int i = 0; i < 5; ++i) {
				int score = Integer.parseInt(br.readLine());
				
				result += score >= 40 ? score : 40;
			}
			
			System.out.println(result / 5);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}
