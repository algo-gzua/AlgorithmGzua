import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;


public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
			int N = Integer.parseInt(br.readLine());
			
			String[] s = br.readLine().split(" ");
			int[] arr = new int[N];
			
			for (int i = 0; i < N; ++i) {
				arr[i] = Integer.parseInt(s[i]);
			}
			
			Arrays.sort(arr);
			
			int q = Integer.parseInt(br.readLine());
			s = br.readLine().split(" ");
			
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < q; ++i) {
				int target = Integer.parseInt(s[i]);
				
				int left = 0;
				int right = N - 1;
				
				boolean isExist = false;
				while (left <= right) {
					int mid = (left + right) / 2;
					
					if (arr[mid] == target) {
						isExist = true;
						break;
					} else if (arr[mid] > target){
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				}
				
				if (isExist) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
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
