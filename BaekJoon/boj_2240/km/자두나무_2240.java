import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");
            int T = Integer.parseInt(s[0]);
            int W = Integer.parseInt(s[1]);

            int[][][] dp = new int[2][T + 1][W + 2];

            for (int i = 1; i <= T; ++i) {
                int tree = Integer.parseInt(br.readLine());

                for (int j = 1; j <= W + 1; ++j) {
                    if (i == 1 && j == 1) {
                        if (tree == 1) {
                            dp[0][i][j] = 1;
                            dp[1][i][j] = 0;
                        } else {
                            dp[0][i][j] = 0;
                            dp[1][i][j] = 0;
                        }
                    } else {
                        if (tree == 1) {
                            dp[0][i][j] = Math.max(dp[0][i][j], Math.max(dp[0][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1));
                            dp[1][i][j] = Math.max(dp[1][i][j], Math.max(dp[0][i - 1][j - 1], dp[1][i - 1][j]));
                        } else {
                            dp[0][i][j] = Math.max(dp[0][i][j], Math.max(dp[0][i - 1][j], dp[1][i - 1][j - 1]));
                            dp[1][i][j] = Math.max(dp[1][i][j], Math.max(dp[0][i - 1][j - 1] + 1, dp[1][i - 1][j] + 1));
                        }
                    }
                }
            }

            int result = 0;
            for (int i = 1; i <= W + 1; ++i) {
                result = Math.max(result, Math.max(dp[0][T][i], dp[1][T][i]));
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