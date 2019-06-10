import java.io.*;
import java.util.Arrays;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());
            int[] score = new int[101];
            String[] s;

            for (int t = 1; t <= T; ++t) {
                int n = Integer.parseInt(br.readLine());

                Arrays.fill(score, 0);

                s = br.readLine().split(" ");

                for (int i = 0; i < 1000; ++i) {
                    score[Integer.parseInt(s[i])]++;
                }

                int maxIndex = 0;
                for (int i = 1; i <= 100; ++i) {
                    if (score[maxIndex] <= score[i]) {
                        maxIndex = i;
                    }
                }

                System.out.println("#" + n + " " + maxIndex);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
