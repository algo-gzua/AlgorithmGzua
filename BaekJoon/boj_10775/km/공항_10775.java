import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	int[] parent;
	
	private int find(int x) {
		if (x == parent[x]) {
			return x;
		}
		
		return parent[x] = find(parent[x]);
	}
	
	private void union(int a, int b) {
		int rootA = find(a);
		int rootB = find(b);
		
		parent[rootA] = rootB;
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int G = Integer.parseInt(br.readLine());
			int P = Integer.parseInt(br.readLine());
			
			parent = new int[G + 1];
			
			for (int i = 1; i <= G; ++i) {
				parent[i] = i;
			}
			
			int result = 0;
			for (int i = 1; i <= P; ++i) {
				int gi = Integer.parseInt(br.readLine());
				
				int docking = find(gi);
				if (docking != 0) {
					union(docking, docking - 1);
					result++;
				} else {
					break;
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
