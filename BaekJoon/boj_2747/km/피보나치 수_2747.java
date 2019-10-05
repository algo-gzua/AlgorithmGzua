import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int[] dp = new int[46];

            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i <= n; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }

            System.out.println(dp[n]);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}