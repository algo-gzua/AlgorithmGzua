import java.io.*;
import java.util.Arrays;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());
                        
            for (int t = 1; t <= T; ++t) {
            	int N = Integer.parseInt(br.readLine());
            	
            	int turn = 1;
            	boolean[] rooms = new boolean[N + 1];
                Arrays.fill(rooms, true);
                
                turn++;
                
                while (turn <= N) {
	                for (int i = 1; i <= N; ++i) {
	                	if (i % turn == 0) {
	                		rooms[i] = !rooms[i];
	                	}
	                }
	                turn++;
                }
                
            	int result = 0;
            	for (int i = 1; i <= N; ++i) {
            		if (rooms[i]) {
            			result++;
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