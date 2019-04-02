import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            String s;
            int front, end;
            boolean isCheck;
            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                s = br.readLine();

                isCheck = false;
                front = 0;
                end = s.length() - 1;

                while (front <= end) {
                    if (s.charAt(front) != s.charAt(end)) {
                        isCheck = true;
                        break;
                    }
                    front++;
                    end--;
                }

                if (isCheck) {
                    sb.append("#").append(t).append(" 0\n");
                } else {
                    sb.append("#").append(t).append(" 1\n");
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
