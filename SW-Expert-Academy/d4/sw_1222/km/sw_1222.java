import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= 10; ++t) {
                int n = Integer.parseInt(br.readLine());
                String s = br.readLine();

                int result = 0;
                for (int i = 0; i < n; ++i) {
                    if ((i & 1) == 0) {
                        result += s.charAt(i) - '0';
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