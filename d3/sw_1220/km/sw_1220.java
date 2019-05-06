import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int[][] arr;

            for (int t = 1; t <= 10; ++t) {
                int N = Integer.parseInt(br.readLine(), 10);

                arr = new int[N][N];

                String[] s;
                for (int i = 0; i < N; ++i) {
                    s = br.readLine().split(" ");
                    for (int j = 0; j < N; ++j) {
                        arr[i][j] = Integer.parseInt(s[j]);
                    }
                }

                int result = 0;
                for (int i = 0; i < N; ++i) {
                    // -1: default, 1: N극(빨강), 2: S극(파랑)
                    int curr = 0;

                    for (int j = 0; j < N; ++j) {
                        if (arr[j][i] == 0) {
                            continue;
                        }

                        if (curr == 0) {
                            // S극이면 그냥 떨어짐
                            if (arr[j][i] == 2) {
                                continue;
                            }

                            curr = arr[j][i];
                        }
                        else {
                            // 현재가 N극일 때
                            if (curr == 1) {
                                // 아래가 S극이면 + 1
                                if (arr[j][i] == 2) {
                                    result++;
                                    curr = 2;
                                }
                            }
                            // 현재가 S극일 때
                            else if (curr == 2) {
                                // 아래가 N극이면 현재를 바꿈
                                if (arr[j][i] == 1) {
                                    curr = 1;
                                }
                            }
                        }
                    }
                }

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