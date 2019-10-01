import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	class Node {
		int z;
		int y;
		int x;
		int distance;
		
		Node (int z, int y, int x, int distance) {
			this.z = z;
			this.y = y;
			this.x = x;
			this.distance = distance;
		}
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			char[][][] arr;
			boolean[][][] visit;
			int[][] direct = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

			while (true) {
				String[] s = br.readLine().split(" ");
				int L = Integer.parseInt(s[0]);
				int R = Integer.parseInt(s[1]);
				int C = Integer.parseInt(s[2]);
				
				if (L == 0 && R == 0 && C == 0) {
					break;
				}
				
				arr = new char[L][R][C];
				visit = new boolean[L][R][C];
				int sL = 0;
				int sR = 0;
				int sC = 0;
				
				String input;
				for (int l = 0; l < L; ++l) {
					for (int r = 0; r < R; ++r) {
						input = br.readLine();
						for (int c = 0; c < C; ++c) {
							arr[l][r][c] = input.charAt(c);
							
							if (arr[l][r][c] == 'S') {
								sL = l;
								sR = r;
								sC = c;
							}
						}
					}
					
					// 공백
					br.readLine();
				}
				
				Queue<Node> q = new LinkedList<>();
				visit[sL][sR][sC] = true;
				q.add(new Node(sL, sR, sC, 0));
				
				int result = 0;
				while (!q.isEmpty()) {
					Node node = q.poll();
					
					if (arr[node.z][node.y][node.x] == 'E') {
						result = node.distance;
						break;
					}
					
					for (int i = 0; i < 6; ++i) {
						int newZ = node.z + direct[i][0];
						int newY = node.y + direct[i][1];
						int newX = node.x + direct[i][2];
						
						if (newZ >= L || newZ < 0 || newY >= R || newY < 0 || newX >= C || newX < 0) {
							continue;
						}
						
						if(visit[newZ][newY][newX]) {
							continue;
						}
						
						if (arr[newZ][newY][newX] != '#') {
							visit[newZ][newY][newX] = true;
							q.add(new Node(newZ, newY, newX, node.distance + 1));
						}
					}
				}
				
				if (result == 0) {
					System.out.println("Trapped!");
				} else {
					System.out.println("Escaped in " + result + " minute(s).");
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