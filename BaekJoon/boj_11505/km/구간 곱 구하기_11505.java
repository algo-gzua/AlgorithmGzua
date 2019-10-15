import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
			
			String[] s = br.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			int K = Integer.parseInt(s[2]);
			
			int size = 1;
			
			while (size < N) {
				size <<= 1;
			}
			
			long[] arr = new long[size * 2];
			
			for (int i = size; i < size + N; ++i) {
				arr[i] = Long.parseLong(br.readLine());
			}
			
			for (int i = size + N; i < size * 2; ++i) {
				arr[i] = -1;
			}
			
			int curr = size;
			while (curr > 1) {
				for (int i = curr; i < curr * 2; i += 2) {
					if (arr[i] == -1) {
						arr[i / 2] = -1;
					} else if (arr[i + 1] == -1) {
						arr[i / 2] = arr[i];
					} else {
						arr[i / 2] = (arr[i] * arr[i + 1]) % 1000000007;
					}
				}
				curr /= 2;
			}
			
			for (int i = 0; i < M + K; ++i) {
				s = br.readLine().split(" ");
				
				int a = Integer.parseInt(s[0]);
				int b = Integer.parseInt(s[1]);
				int c = Integer.parseInt(s[2]);
				
				if (a == 1) {
					// 수정
					int index = size + b - 1;
					arr[index] = c;
					
					while (index > 1) {
						if (index % 2 == 0) {
							if (arr[index] == -1) {
								arr[index / 2] = -1;
							} else if (arr[index + 1] == -1) {
								arr[index / 2] = arr[index];
							} else {
								arr[index / 2] = (arr[index] * arr[index + 1]) % 1000000007;
							}
						} else {
							if (arr[index - 1] == -1) {
								arr[index / 2] = -1;
							} else if (arr[index] == -1) {
								arr[index / 2] = arr[index - 1];
							} else {
								arr[index / 2] = (arr[index - 1] * arr[index]) % 1000000007;
							}
						}
						index /= 2;
					}
				} else {	
					// 출력
					int left = size + b - 1;
					int right = size + c - 1;
					
					long result = 1;
					while (left < right) {
						if (left % 2 != 0) {
							result = (result * arr[left]) % 1000000007;
							left++;
						}
						
						if (right % 2 == 0) {
							result = (result * arr[right]) % 1000000007;
							right--;
						}
						
						left /= 2;
						right /= 2;
					}
					if (left == right) {
						result = (result * arr[left]) % 1000000007;
					}
					
					System.out.println(result);
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
