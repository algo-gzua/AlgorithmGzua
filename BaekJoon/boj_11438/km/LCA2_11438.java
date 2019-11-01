import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	final int HEIGHT = 20; 
	int[][] parent;
	int[] depth;
	boolean[] visit;
	ArrayList<Integer>[] arrayList;
	
	private void dfs(int curr) {
		for (int next : arrayList[curr]) {
			if (visit[next]) {
				continue;
			}
			
			depth[next] = depth[curr] + 1;
			parent[next][0] = curr;
			visit[next] = true;
			dfs(next);
		}
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			 BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
			int N = Integer.parseInt(br.readLine());
			
			depth = new int[N + 1];
			visit = new boolean[N + 1];
			parent = new int[N + 1][HEIGHT];
			arrayList = new ArrayList[N + 1];
			
			for (int i = 1; i <= N; ++i) {
				arrayList[i] = new ArrayList<>();
			}
			
			StringTokenizer st;
			for (int i = 0; i < N - 1; ++i) {
				st = new StringTokenizer(br.readLine(), " ");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				arrayList[a].add(b);
				arrayList[b].add(a);
			}
			
			// 깊이 설정 및 바로 위에 부모 초기화
			visit[1] = true;
			dfs(1);
			
			// 부모의 부모 설정
			for (int j = 0; j < HEIGHT - 1; ++j) {
				for (int i = 2; i <= N; ++i) {
					parent[i][j + 1] = parent[parent[i][j]][j];
				}
			}
			
			StringBuilder sb = new StringBuilder();
			int M = Integer.parseInt(br.readLine());
			for (int i = 0; i < M; ++i) {
				st = new StringTokenizer(br.readLine(), " ");
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				
				// 공통 조상 찾기
				if (depth[u] < depth[v]) {
					int temp = u;
					u = v;
					v = temp;
				}
				
				int diff = depth[u] - depth[v];
				
				int index = 0;
				while (diff > 0) {
					if (diff % 2 == 1) {
						u = parent[u][index];
					}
					
					index++;
					diff /= 2;
				}
				
				if (u != v) {
					for (int k = HEIGHT - 1; k >= 0; --k) {
						if (parent[u][k] != parent[v][k]) {
							u = parent[u][k];
							v = parent[v][k];
						}						
					}
					u = parent[u][0];
				}
				
				sb.append(u).append("\n");
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