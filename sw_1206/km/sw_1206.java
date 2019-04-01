import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            int[] arr;
            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= 10; ++t) {
                int N = Integer.parseInt(br.readLine());

                arr = new int[N+1];

                String[] s = br.readLine().split(" ");

                for (int i = 1; i <= N; ++i) {
                    arr[i] = Integer.parseInt(s[i-1]);
                }

                int max = 0;
                int result = 0;
                for (int i = 3; i <= N - 2; ++i) {
                    max = Math.max(Math.max(arr[i-2], arr[i-1]), Math.max(arr[i+1], arr[i+2]));

                    if (arr[i] > max) {
                        result += arr[i] - max;
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
