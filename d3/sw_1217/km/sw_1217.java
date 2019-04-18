import java.io.*;

public class Solution {
    private int recursion(int x, int count, int curr) {
        if (count == 0) {
            return curr;
        }

        return recursion(x, count - 1, curr * x);
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            for (int t = 1; t <= 10; ++t) {
                int tc = Integer.parseInt(br.readLine());
                String[] s = br.readLine().split(" ");

                int result = recursion(Integer.parseInt(s[0]), Integer.parseInt(s[1]), 1);

                System.out.println("#"+ tc + " " + result);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
