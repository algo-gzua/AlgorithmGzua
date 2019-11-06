import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    class Node {
        int next;
        int w;

        Node (int next, int w) {
            this.next = next;
            this.w = w;
        }
    }

    int[] parent;
    ArrayList<Node>[] arrayList;
    boolean[] visit;
    int[] distance;

    private int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    private void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        parent[rootB] = rootA;
    }

    private void dfs(int curr) {
        for (Node n : arrayList[curr]) {
            if (!visit[n.next]) {
                visit[n.next] = true;
                distance[n.next] = distance[curr] + n.w;
                dfs(n.next);
            }
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringTokenizer st;

            StringBuilder sb = new StringBuilder();
            while (true) {
                st = new StringTokenizer(br.readLine(), " ");

                int N = Integer.parseInt(st.nextToken());
                int M = Integer.parseInt(st.nextToken());

                if (N == 0 && M == 0) {
                    break;
                }

                ArrayList<Node> query = new ArrayList<>();
                parent = new int[N + 1];
                arrayList = new ArrayList[N + 1];
                visit = new boolean[N + 1];
                distance = new int[N + 1];

                for (int i = 1; i <= N; ++i) {
                    parent[i] = i;
                    arrayList[i] = new ArrayList<>();
                }

                for (int m = 0; m < M; ++m) {
                    st = new StringTokenizer(br.readLine(), " ");

                    String flag = st.nextToken();
                    int a = Integer.parseInt(st.nextToken());
                    int b = Integer.parseInt(st.nextToken());

                    if (flag.equals("!")) {
                        int w = Integer.parseInt(st.nextToken());

                        arrayList[a].add(new Node(b, w));
                        arrayList[b].add(new Node(a, -w));

                        union(a, b);
                    } else {
                        if (find(a) != find(b)) {
                            query.add(new Node(-1, -1));
                        } else {
                            query.add(new Node(a, b));
                        }
                    }
                }

                // 트리 만들기

                for (int i = 1; i <= N; ++i) {
                    if (!visit[i]) {
                        visit[i] = true;
                        dfs(i);
                    }
                }

                // 쿼리 돌리기
                for (Node n : query) {
                    if (n.next == -1 && n.w == -1) {
                        sb.append("UNKNOWN\n");
                    } else {
                        sb.append(distance[n.w] - distance[n.next]).append("\n");
                    }
                }
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