import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    int[] parent;
    int[] relation;

    private int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    private void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            parent[rootB] = rootA;
            relation[rootA] += relation[rootB];
            relation[rootB] = relation[rootA];
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());


            for (int t = 0; t < T; ++t) {
                int F = Integer.parseInt(br.readLine());

                parent = new int[100010];
                relation = new int[100010];
                for (int i = 1; i < 100010; ++i) {
                    parent[i] = i;
                    relation[i] = 1;
                }

                HashMap<String, Integer> map = new HashMap<>();
                int index = 1;
                for (int i = 0; i < F; ++i) {
                    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

                    String A = st.nextToken();
                    String B = st.nextToken();

                    if (!map.containsKey(A)) {
                        map.put(A, index++);
                    }
                    if (!map.containsKey(B)) {
                        map.put(B, index++);
                    }

                    int a = map.get(A);
                    int b = map.get(B);
                    if (find(a) != find(b)) {
                        union(a, b);
                    }

                    System.out.println(relation[find(a)]);
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