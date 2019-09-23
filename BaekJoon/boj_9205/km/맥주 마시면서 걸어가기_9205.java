import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
	class Spot {
		int y;
		int x;
		
		Spot (int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	Spot home;
	ArrayList<Spot> convenience;
	boolean[] visit;
	Spot destination;
	String result;
	
	private void dfs(Spot spot) {
		if (Math.abs((spot.x - destination.x)) + Math.abs((spot.y - destination.y)) <= 1000) {
			result = "happy";
			
			Arrays.fill(visit, true);
			return;
		}
		
		for (int i = 0; i < convenience.size(); ++i) {
			if (Math.abs((spot.x - convenience.get(i).x)) + Math.abs((spot.y - convenience.get(i).y)) <= 1000) {
				if (!visit[i]) {
					visit[i] = true;
					dfs(convenience.get(i));
				}
			}
		}
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int t = Integer.parseInt(br.readLine());
			
			String[] s;
			for (int tc = 0; tc < t; ++tc) {
				int n = Integer.parseInt(br.readLine());
				
				s = br.readLine().split(" ");
				home = new Spot(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
				convenience = new ArrayList<>();
				visit = new boolean[n];
				for (int i = 0; i < n; ++i) {
					s = br.readLine().split(" ");
						
					convenience.add(new Spot(Integer.parseInt(s[0]), Integer.parseInt(s[1])));
				}
				s = br.readLine().split(" ");
				destination = new Spot(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
				
				result = "sad";
				
				dfs(home);
				
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