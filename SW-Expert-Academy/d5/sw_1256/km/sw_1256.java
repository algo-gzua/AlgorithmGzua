import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            StringBuilder sb = new StringBuilder();

            ArrayList<String> list;
            for (int t = 1; t <= T; ++t) {
                int K = Integer.parseInt(br.readLine());
                String s = br.readLine();

                list = new ArrayList<>();

                String temp = "";
                for (int i = s.length() - 1; i >= 0; --i) {
                    temp = s.charAt(i) + temp;
                    list.add(temp);
                }

                Collections.sort(list);

                sb.append("#").append(t).append(" ").append(list.get(K - 1)).append("\n");
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