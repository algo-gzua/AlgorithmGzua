import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int[][] board;
            for (int t = 1; t <= 10; ++t) {
                int tc = Integer.parseInt(br.readLine(), 10);
                board = new int[100][100];

                // 보드 초기화
                String[] s;
                int endPoint = -1;
                for (int i = 0; i < 100; ++i) {
                    s = br.readLine().split(" ");
                    for (int j = 0; j < 100; ++j) {
                        board[i][j] = Integer.parseInt(s[j]);

                        if (board[i][j] == 2) {
                            endPoint = j;
                        }
                    }
                }

                // 끝점에서부터 양옆을 확인하며 위로 탐색
                // 끝점은 y = 99, x = endPoint

                int y = 99;
                int x = endPoint;
                // up: 1, right: 2, left: 3
                int direct = 1;
                while (y > 0) {
                    if (direct == 1) {
                        if (x - 1 >= 0) {
                            if (board[y][x - 1] == 1) {
                                direct = 3;
                                x--;
                                continue;
                            }
                        }

                        if (x + 1 < 100) {
                            if (board[y][x + 1] == 1) {
                                direct = 2;
                                x++;
                                continue;
                            }
                        }

                        y--;
                    }
                    else if (direct == 3) {
                        if (x - 1 >= 0) {
                            if (board[y][x - 1] == 0) {
                                direct = 1;
                                y--;
                            }
                            else {
                                x--;
                            }
                        }
                        else {
                            direct = 1;
                            y--;
                        }
                    }
                    else {
                        if (x + 1 < 100) {
                            if (board[y][x + 1] == 0) {
                                direct = 1;
                                y--;
                            }
                            else {
                                x++;
                            }
                        }
                        else {
                            direct = 1;
                            y--;
                        }
                    }
                }

                System.out.println("#" + tc + " " + x);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
