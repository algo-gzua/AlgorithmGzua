import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());
            int[][] arr;

            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                sb.append("#").append(t).append("\n");
                int N = Integer.parseInt(br.readLine());

                arr = new int[N + 1][N + 1];

                arr[1][1] = 1;
                sb.append(arr[1][1]).append("\n");
                for (int i = 2; i <= N; ++i) {
                    for (int j = 1; j <= i; ++j) {
                        arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
                        if (arr[i][j] != 0) {
                            sb.append(arr[i][j]).append(" ");
                        }
                    }
                    sb.append("\n");
                }
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
