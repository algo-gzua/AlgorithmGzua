import java.io.*;
import java.util.ArrayList;

public class Main {
    class Node {
        int destination;
        int distance;

        Node (int destination, int distance) {
            this.destination = destination;
            this.distance = distance;
        }
    }

    ArrayList<Node>[] arrayList;
    int[] memo;
    int[] depth;
    int[][] parent;
    boolean[] visit;
    final int HEIGHT = 20;

    private void dfs(int curr) {
        for (Node next : arrayList[curr]) {
            if (visit[next.destination]) {
                continue;
            }

            visit[next.destination] = true;
            depth[next.destination] = depth[curr] + 1;
            memo[next.destination] = memo[curr] + next.distance;
            parent[next.destination][0] = curr;
            dfs(next.destination);
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int N = Integer.parseInt(br.readLine());

            arrayList = new ArrayList[N + 1];
            memo = new int[N + 1];
            depth = new int[N + 1];
            parent = new int[N + 1][HEIGHT];
            visit = new boolean[N + 1];

            for (int i = 0; i <= N; ++i) {
                arrayList[i] = new ArrayList<>();
            }

            String[] s;
            for (int i = 0; i < N - 1; ++i) {
                s = br.readLine().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);
                int c = Integer.parseInt(s[2]);

                arrayList[a].add(new Node(b, c));
                arrayList[b].add(new Node(a, c));
            }

            visit[1] = true;
            dfs(1);

            for (int j = 0; j < HEIGHT - 1; ++j) {
                for (int i = 2; i <= N; ++i) {
                    parent[i][j + 1] = parent[parent[i][j]][j];
                }
            }

            int M = Integer.parseInt(br.readLine());

            for (int i = 0; i < M; ++i) {
                s = br.readLine().split(" ");
                int originU = Integer.parseInt(s[0]);
                int originV = Integer.parseInt(s[1]);
                int u = originU;
                int v = originV;

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

                    diff /= 2;
                    index++;
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

                // u는 공통조상이다.
                int result = (memo[originU] - memo[u]) + (memo[originV] - memo[u]);
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