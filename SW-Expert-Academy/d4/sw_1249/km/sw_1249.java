import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    int y;
    int x;

    Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            int[][] direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            StringBuilder sb = new StringBuilder();
            int[][] arr;
            int[][] result;
            for (int t = 1; t <= T; ++t) {
                int N = Integer.parseInt(br.readLine());

                arr = new int[N][N];
                result = new int[N][N];

                for (int i = 0; i < N; ++i) {
                    Arrays.fill(result[i], -1);
                }

                for (int i = 0; i < N; ++i) {
                    String s = br.readLine();

                    for (int j = 0; j < N; ++j) {
                        arr[i][j] = s.charAt(j) - '0';
                    }
                }

                Queue<Node> queue = new LinkedList<>();

                queue.offer(new Node(0, 0));
                result[0][0] = arr[0][0];

                while (!queue.isEmpty()) {
                    Node n = queue.poll();

                    // 4방향 탐색
                    for (int i = 0; i < 4; ++i) {
                        int y = n.y + direction[i][0];
                        int x = n.x + direction[i][1];

                        // 범위 바깥일 경우
                        if (y < 0 || x < 0 || y >= N || x >= N) {
                            continue;
                        }

                        if (result[y][x] == -1) {
                            result[y][x] = result[n.y][n.x] + arr[y][x];
                            queue.offer(new Node(y, x));
                        } else {
                            if (result[y][x] > result[n.y][n.x] + arr[y][x]) {
                                result[y][x] = result[n.y][n.x] + arr[y][x];
                                queue.offer(new Node(y, x));
                            }
                        }
                    }
                }

                sb.append("#").append(t).append(" ").append(result[N-1][N-1]).append("\n");
            }

            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
