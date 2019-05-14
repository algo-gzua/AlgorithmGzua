import java.io.*;
import java.util.HashMap;
import java.util.Stack;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            HashMap<Character, Integer> map = new HashMap<>();

            map.put('(', 0);
            map.put('+', 1);
            map.put('*', 2);
            map.put(')', 3);

            for (int t = 1; t <= 10; ++t) {
                int n = Integer.parseInt(br.readLine());
                String s = br.readLine();

                StringBuilder sb = new StringBuilder();

                Stack<Character> stack = new Stack<>();
                for (int i = 0; i < n; ++i) {
                    char c = s.charAt(i);

                    if (map.containsKey(c)) {
                        if (c == '(') {
                            stack.push(c);
                            continue;
                        }
                        else if (c == ')') {
                            while (stack.peek() != '(') {
                                sb.append(stack.pop());
                            }

                            // (
                            stack.pop();
                            continue;
                        }
                        else if (!stack.isEmpty()) {
                            while (map.get(stack.peek()) >= map.get(c)) {
                                sb.append(stack.pop());

                                if (stack.isEmpty()) {
                                    break;
                                }
                            }
                        }

                        stack.push(c);
                    }
                    else {
                        sb.append(c);
                    }
                }

                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }

                Stack<Integer> stack2 = new Stack<>();

                int size = sb.length();

                for (int i = 0; i < size; ++i) {
                    if (sb.charAt(i) == '+') {
                        int a = stack2.pop();
                        int b = stack2.pop();

                        stack2.push(a + b);
                    }
                    else if (sb.charAt(i) == '*') {
                        int a = stack2.pop();
                        int b = stack2.pop();

                        stack2.push(a * b);
                    }
                    else {
                        stack2.push(sb.charAt(i) - '0');
                    }
                }

                System.out.println("#" + t + " " + stack2.pop());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}