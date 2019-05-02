import java.io.*;
import java.util.HashMap;
import java.util.Stack;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            HashMap<Character, Integer> map = new HashMap<>();

            map.put('+', 1);
            map.put('*', 2);

            for (int t = 1; t <= 10; ++t) {
                int n = Integer.parseInt(br.readLine(), 10);
                String s = br.readLine();
                // 후위 표기식으로 변환
                Stack<Character> stack = new Stack<>();

                int size = s.length();
                StringBuilder postFix = new StringBuilder();
                for (int i = 0; i < size; ++i) {
                    if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                        postFix.append(s.charAt(i));
                    }
                    else {
                        if (stack.isEmpty()) {
                            stack.push(s.charAt(i));
                        }
                        else if (map.get(stack.peek()) < map.get(s.charAt(i))) {
                            stack.push(s.charAt(i));
                        }
                        else {
                            while (map.get(stack.peek()) >= map.get(s.charAt(i))) {
                                postFix.append(stack.pop());

                                if (stack.isEmpty()) {
                                    break;
                                }
                            }

                            stack.push(s.charAt(i));
                        }
                    }
                }

                while (!stack.isEmpty()) {
                    postFix.append(stack.pop());
                }

                // postFix.toString()은 후위 표기식

                // 후위 표기식 연산
                Stack<Integer> numberStack = new Stack<>();

                for (int i = 0; i < postFix.length(); ++i) {
                    if (postFix.charAt(i) >= '0' && postFix.charAt(i) <= '9') {
                        numberStack.push(postFix.charAt(i) - '0');
                    }
                    else {
                        if (postFix.charAt(i) == '*') {
                            int first = numberStack.pop();
                            int second = numberStack.pop();

                            numberStack.push(first * second);
                        }
                        else if (postFix.charAt(i) == '+') {
                            int first = numberStack.pop();
                            int second = numberStack.pop();

                            numberStack.push(first + second);
                        }
                    }
                }

                System.out.println("#"+ t + " " + numberStack.pop());
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
