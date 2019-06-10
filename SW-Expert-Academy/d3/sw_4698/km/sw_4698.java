import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            boolean[] eratos = new boolean[1000001];

            eratos[0] = eratos[1] = true;

            for (int i = 2; i <= 1000000; ++i) {
                if (!eratos[i]) {
                    for (int j = 2; j <= 1000000 / i; ++j) {
                        if (!eratos[i * j]) {
                            eratos[i * j] = true;
                        }
                    }
                }
            }

            StringBuilder sb = new StringBuilder();
            String[] s;
            for (int t = 1; t <= T; ++t) {
                s = br.readLine().split(" ");

                int D = Integer.parseInt(s[0]);
                int A = Integer.parseInt(s[1]);
                int B = Integer.parseInt(s[2]);

                int result = 0;
                for (int i = A; i <= B; ++i) {
                    if (!eratos[i]) {
                        String temp = String.valueOf(i);

                        for (int j = 0; j < temp.length(); ++j) {
                            if (temp.charAt(j) == D + '0') {
                                result++;
                                break;
                            }
                        }
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
