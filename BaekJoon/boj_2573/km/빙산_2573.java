import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int N;
    int M;
    int[][] arr;
    int[][] reduce;
    int[][] direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    boolean[][] visit;

    private void dfs(int y, int x) {
        for (int i = 0; i < 4; ++i) {
            int newY = y + direct[i][0];
            int newX = x + direct[i][1];

            if (newY >= N || newY < 0 || newX >= M || newX < 0) {
                continue;
            }

            if (visit[newY][newX]) {
                continue;
            }

            if (arr[newY][newX] > 0) {
                visit[newY][newX] = true;
                dfs(newY, newX);
            }
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");
            N = Integer.parseInt(s[0]);
            M = Integer.parseInt(s[1]);
            arr = new int[N][M];
            reduce = new int[N][M];
            visit = new boolean[N][M];

            for (int i = 0; i < N; ++i) {
                s = br.readLine().split(" ");

                for (int j = 0; j < M; ++j) {
                    arr[i][j] = Integer.parseInt(s[j]);
                }
            }

            int count = 0;
            int turn = 0;
            while (count < 2) {
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        // 줄어들 빙산 체크
                        if (arr[i][j] == 0) {
                            for (int k = 0; k < 4; ++k) {
                                int newY = i + direct[k][0];
                                int newX = j + direct[k][1];

                                if (newY >= N || newY < 0 || newX >= M || newX < 0) {
                                    continue;
                                }

                                if (arr[newY][newX] > 0) {
                                    reduce[newY][newX]++;
                                }
                            }
                        }
                    }
                }

                // 빙산 제거
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        if (arr[i][j] - reduce[i][j] < 0) {
                            arr[i][j] = 0;
                        } else {
                            arr[i][j] -= reduce[i][j];
                        }
                        reduce[i][j] = 0;
                    }
                }

                for (int i = 0; i < N; ++i) {
                    Arrays.fill(visit[i], false);
                }

                count = 0;
                // dfs돌려서 빙산 개수 세자
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        if (!visit[i][j] && arr[i][j] > 0) {
                            visit[i][j] = true;
                            dfs(i, j);
                            count++;
                        }
                    }
                }
                turn++;

                if (count == 0) {
                    System.out.println(0);
                    return;
                }
            }

            System.out.println(turn);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}