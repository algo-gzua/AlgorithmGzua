import java.io.*;
import java.util.HashMap;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            String[] s;
            StringBuilder sb = new StringBuilder();

            // 맵을 만들자
            HashMap<Character, Integer> map = new HashMap<>();

            for (int i = 'A'; i <= 'Z'; ++i) {
                if (i == 'A' || i == 'D' || i == 'O' || i == 'P' || i == 'Q' || i == 'R') {
                    map.put((char)i, 1);
                } else if (i == 'B') {
                    map.put((char)i, 2);
                } else {
                    map.put((char)i, 0);
                }
            }

            boolean isCheck;
            for (int t = 1; t <= T; ++t) {
                s = br.readLine().split(" ");

                if (s[0].length() != s[1].length()) {
                    sb.append("#").append(t).append(" DIFF\n");
                    continue;
                }

                isCheck = false;
                for (int i = 0; i < s[0].length(); ++i) {
                    if (!map.get(s[0].charAt(i)).equals(map.get(s[1].charAt(i)))) {
                        isCheck = true;
                        break;
                    }
                }

                if (isCheck) {
                    sb.append("#").append(t).append(" DIFF\n");
                } else {
                    sb.append("#").append(t).append(" SAME\n");
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
