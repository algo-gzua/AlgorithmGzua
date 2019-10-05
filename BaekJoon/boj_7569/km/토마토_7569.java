import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    class Node {
        int z;
        int y;
        int x;
        int count;

        Node (int z, int y, int x, int count) {
            this.z = z;
            this.y = y;
            this.x = x;
            this.count = count;
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");

            int M = Integer.parseInt(s[0]);
            int N = Integer.parseInt(s[1]);
            int H = Integer.parseInt(s[2]);

            int[][][] tomato = new int[H][N][M];
            boolean[][][] visit = new boolean[H][N][M];
            int[][] direct = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

            Queue<Node> queue = new LinkedList<>();
            for (int h = 0; h < H; ++h) {
                for (int n = 0; n < N; ++n) {
                    s = br.readLine().split(" ");
                    for (int m = 0; m < M; ++m) {
                        tomato[h][n][m] = Integer.parseInt(s[m]);
                        if (tomato[h][n][m] == 1) {
                            queue.add(new Node(h, n, m, 0));
                            visit[h][n][m] = true;
                        }
                    }
                }
            }

            int result = 0;
            while (!queue.isEmpty()) {
                Node n = queue.poll();

                result = Math.max(result, n.count);

                for (int i = 0; i < 6; ++i) {
                    int newZ = n.z + direct[i][0];
                    int newY = n.y + direct[i][1];
                    int newX = n.x + direct[i][2];

                    if (newZ >= H || newZ < 0 || newY >= N || newY < 0 || newX >= M || newX < 0) {
                        continue;
                    }

                    if (visit[newZ][newY][newX] || tomato[newZ][newY][newX] == -1) {
                        continue;
                    }

                    visit[newZ][newY][newX] = true;
                    tomato[newZ][newY][newX] = 1;
                    queue.add(new Node(newZ, newY, newX, n.count + 1));
                }
            }

            for (int h = 0; h < H; ++h) {
                for (int n = 0; n < N; ++n) {
                    for (int m = 0; m < M; ++m) {
                        if (tomato[h][n][m] == 0) {
                            System.out.println("-1");
                            return;
                        }
                    }
                }
            }

            System.out.println(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}