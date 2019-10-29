import java.io.*;
import java.util.ArrayList;

public class Main {
    ArrayList<Integer>[] arrayList;
    boolean[] visit;
    int[] depth;
    int[][] parent;
    final int LENGTH = 20;

    private void dfs(int curr) {
        for (Integer next : arrayList[curr]) {
            if (visit[next]) {
                continue;
            }

            visit[next] = true;
            depth[next] = depth[curr] + 1;
            parent[next][0] = curr;
            dfs(next);
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int N = Integer.parseInt(br.readLine());

            arrayList = new ArrayList[N + 1];
            visit = new boolean[N + 1];
            depth = new int[N + 1];
            parent = new int[N + 1][LENGTH];

            for (int i = 0; i <= N; ++i) {
                arrayList[i] = new ArrayList<>();
            }

            String[] s;
            for (int i = 1; i < N; ++i) {
                s = br.readLine().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);

                arrayList[a].add(b);
                arrayList[b].add(a);
            }

            // 트리 만들기(만들면서 부모와 깊이 채우기)
            visit[1] = true;
            dfs(1);

            // 부모 테이블 만들기
            for (int j = 0; j < LENGTH - 1; ++j) {
                for (int i = 2; i <= N; ++i) {
                    parent[i][j + 1] = parent[parent[i][j]][j];
                }
            }

            int M = Integer.parseInt(br.readLine());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < M; ++i) {
                s = br.readLine().split(" ");
                int u = Integer.parseInt(s[0]);
                int v = Integer.parseInt(s[1]);

                // u를 더 깊어지게 만듦
                if (depth[u] < depth[v]) {
                    int temp = u;
                    u = v;
                    v = temp;
                }
                int diff = depth[u] - depth[v];

                // 두 점의 높이 같게 하기
                int binary = 0;
                while (diff > 0) {
                    if (diff % 2 == 1) {
                        u = parent[u][binary];
                    }
                    diff /= 2;
                    binary++;
                }

                // 공통 부모 찾기
                if (u != v) {
                    for (int k = LENGTH - 1; k >= 0; --k) {
                        if (parent[u][k] != 0 && parent[u][k] != parent[v][k]) {
                            u = parent[u][k];
                            v = parent[v][k];
                        }
                    }
                    // 두 정점의 부모가 같으므로 한 번 더 올림
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