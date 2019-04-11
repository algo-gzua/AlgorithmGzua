import java.io.*;

public class Solution {
    public void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            String[] s;
            int[] arr;

            String[] numbers;
            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                s = br.readLine().split(" ");
                int N = Integer.parseInt(s[0]);
                arr = new int[N + 1];

                numbers = br.readLine().split(" ");

                int K = Integer.parseInt(s[1]);
                for (int i = 0; i < K; ++i) {
                    arr[Integer.parseInt(numbers[i])]++;
                }

                sb.append("#").append(t).append(" ");
                for (int i = 1; i <= N; ++i) {
                    if (arr[i] == 0) {
                        sb.append(i).append(" ");
                    }
                }
                sb.append("\n");
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