import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            int[] arr;
            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                int N = Integer.parseInt(br.readLine());
                arr = new int[N + 1];

                String[] s = br.readLine().split(" ");

                for (int i = 1; i <= N; ++i) {
                    arr[i] = Integer.parseInt(s[i - 1]);
                }

                int curr = arr[N];
                long result = 0;
                for (int i = N - 1; i >= 1; --i) {
                    if (curr > arr[i]) {
                        result += curr - arr[i];
                    } else {
                        curr = arr[i];
                    }
                }

                sb.append("#").append(t).append(" ").append(result).append("\n");
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
