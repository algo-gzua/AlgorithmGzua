import java.io.*;
import java.util.Stack;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= 10; ++t) {
                int N = Integer.parseInt(br.readLine());
                String s = br.readLine();

                Stack<Character> stack = new Stack<>();

                for (int i = 0; i < N; ++i) {
                    if (stack.isEmpty()) {
                        stack.push(s.charAt(i));
                        continue;
                    }

                    // ()
                    if (stack.peek() + 1 == s.charAt(i)) {
                        stack.pop();
                    }
                    // {}, [], <>
                    else if (stack.peek() + 2 == s.charAt(i)) {
                        stack.pop();
                    }
                    else {
                        stack.push(s.charAt(i));
                    }
                }

                if (stack.isEmpty()) {
                    sb.append("#").append(t).append(" 1\n");
                } else {
                    sb.append("#").append(t).append(" 0\n");
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
