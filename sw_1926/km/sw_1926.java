import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int N = Integer.parseInt(br.readLine());

            String s;
            int count;
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= N; ++i) {
                s = String.valueOf(i);

                count = 0;
                for (char c : s.toCharArray()) {
                    if (c == '3' || c == '6' || c == '9') {
                        count++;
                    }
                }

                if (count == 0) {
                    sb.append(s).append(" ");
                } else {
                    for (int c = 0; c < count; ++c) {
                        sb.append("-");
                    }
                    sb.append(" ");
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
