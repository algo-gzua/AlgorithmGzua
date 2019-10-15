import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;


public class Main {
	class Node {
		int index;
		int count;
		
		Node (int index, int count) {
			this.index = index;
			this.count = count;
		}
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			String[] s = br.readLine().split(" ");
			
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			
			ArrayList<Integer>[] list = new ArrayList[N + 1];
			boolean[] visit = new boolean[N + 1];
			
			for (int i = 1; i <= N; ++i) {
				list[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < M; ++i) {
				s = br.readLine().split(" ");
				
				int a = Integer.parseInt(s[0]);
				int b = Integer.parseInt(s[1]);
				
				list[a].add(b);
				list[b].add(a);
			}
			
			Queue<Node> queue = new LinkedList<>();
			visit[1] = true;
			queue.add(new Node(1, 0));
			
			int destination = 0;
			int distance = 0;
			int destinationCount = 0;
			
			while (!queue.isEmpty()) {
				Node curr = queue.poll();
				
				if (distance < curr.count) {
					// 갱신
					distance = curr.count;
					destination = curr.index;
					destinationCount = 1;
				} else if (distance == curr.count) {
					// 카운트 세기
					destination = Math.min(destination, curr.index);
					destinationCount++;
				}
				
				for (int next : list[curr.index]) {
					if (visit[next]) {
						continue;
					}
					
					visit[next] = true;
					queue.add(new Node(next, curr.count + 1));
				}
			}
			
			System.out.println(destination + " " + distance + " " + destinationCount);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}
