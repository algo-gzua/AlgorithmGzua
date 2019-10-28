import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	int N;
	int M;
	ArrayList<Integer>[] arrayList;
	boolean[] visit;
	int maxCount;
	int index;
	int[] resultIndex;

	private int dfs(int curr) {
		int count = 1;

		for (int next : arrayList[curr]) {
			if (!visit[next]) {
				visit[next] = true;
				count += dfs(next);
			}
		}

		return count;
	}

	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");

			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());

			arrayList = new ArrayList[N + 1];
			visit = new boolean[N + 1];

			for (int i = 1; i <= N; ++i) {
				arrayList[i] = new ArrayList<>();
			}

			for (int i = 0; i < M; ++i) {
				st = new StringTokenizer(br.readLine(), " ");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				arrayList[b].add(a);
			}

			maxCount = 0;
			resultIndex = new int[N];
			for (int i = 1; i <= N; ++i) {
				visit[i] = true;
				int count = dfs(i);
				
				Arrays.fill(visit, false);

				if (maxCount < count) {
					maxCount = count;
					index = 0;
					resultIndex[index++] = i;
				} else if (maxCount == count) {
					resultIndex[index++] = i;
				}
			}

			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < index; ++i) {
				sb.append(resultIndex[i]).append(" ");
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