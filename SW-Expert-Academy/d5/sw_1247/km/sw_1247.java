import java.io.*;
import java.util.Arrays;

class Node {
    int x;
    int y;

    Node (int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Solution {
    int[][] arr;
    Node[] nodes;
    boolean[] visit;
    int N;
    int result;
    int value;

    private void dfs(int curr) {
        boolean isComplete = true;
        for (int i = 1; i <= N; ++i) {
            if (!visit[i]) {
                isComplete = false;
                break;
            }
        }

        if (isComplete) {
            value += arr[curr][N + 1];
            result = Math.min(result, value);
            value -= arr[curr][N + 1];
            return;
        }

        for (int i = 1; i <= N; ++i) {
            if (!visit[i]) {
                value += arr[curr][i];
                visit[i] = true;
                dfs(i);
                value -= arr[curr][i];
                visit[i] = false;
            }
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine(), 10);
            final int INF = 2147483647;

            for (int t = 1; t <= T; ++t) {
                N = Integer.parseInt(br.readLine(), 10);

                arr = new int[N + 2][N + 2];
                nodes = new Node[N + 2];
                visit = new boolean[N + 2];

                for (int i = 0; i < N + 2; ++i) {
                    Arrays.fill(arr[i], INF);
                }

                String[] s = br.readLine().split(" ");

                nodes[0] = new Node(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
                nodes[N + 1] = new Node(Integer.parseInt(s[2]), Integer.parseInt(s[3]));

                for (int i = 1; i <= N; ++i) {
                    nodes[i] = new Node(Integer.parseInt(s[(i * 2) + 2]), Integer.parseInt(s[(i * 2) + 3]));
                }

                for (int i = 0; i < N + 1; ++i) {
                    for (int j = i + 1; j < N + 2; ++j) {
                        int dist = Math.abs(nodes[i].x - nodes[j].x) + Math.abs(nodes[i].y - nodes[j].y);

                        if (arr[i][j] > dist) {
                            arr[i][j] = dist;
                            arr[j][i] = dist;
                        }
                    }
                }

                result = INF;
                value = 0;
                visit[0] = true;
                dfs(0);

                System.out.println("#" + t + " " + result);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}