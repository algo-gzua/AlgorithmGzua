import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            int[][] arr;
            int N;
            int num;

            int x;
            int y;
            // 0: right, 1: bottom, 2: left, 3: top
            int direction;
            for (int t = 1; t <= T; ++t) {
                N = Integer.parseInt(br.readLine());
                arr = new int[N + 2][N + 2];
                num = 1;
                direction = 0;

                x = 1;
                y = 1;
                for (int i = 0; i < N*N; ++i) {
                    arr[y][x] = num;
                    num ++;

                    if (direction == 0) {
                        x++;
                        if (x > N || arr[y][x] != 0) {
                            direction = 1;
                            x--;
                            y++;
                        }
                    } else if (direction == 1) {
                        y++;

                        if (y > N || arr[y][x] != 0) {
                            direction = 2;
                            y--;
                            x--;
                        }
                    } else if (direction == 2) {
                        x--;

                        if (x < 1 || arr[y][x] != 0) {
                            direction = 3;
                            x++;
                            y--;
                        }
                    } else if (direction == 3) {
                        y--;

                        if (y < 1 || arr[y][x] != 0) {
                            direction = 0;
                            y++;
                            x++;
                        }
                    }
                }

                System.out.println("#" + t);
                for (int i = 1; i <= N; ++i) {
                    for (int j = 1; j <= N; ++j) {
                        System.out.print(arr[i][j] + " ");
                    }
                    System.out.println();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
