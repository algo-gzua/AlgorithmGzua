import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            ArrayList<Integer>[] list;
            boolean[] visit;

            for (int t = 1; t <= 10; ++t) {
                list = new ArrayList[100];
                visit = new boolean[100];

                for (int i = 0; i < 100; ++i) {
                    list[i] = new ArrayList<>();
                }

                String[] s = br.readLine().split(" ");
                int tc = Integer.parseInt(s[0], 10);
                int N = Integer.parseInt(s[1], 10);

                String[] input = br.readLine().split(" ");

                // 인접 리스트 초기화
                int start = 0;
                for (int i = 0; i < input.length; ++i) {
                    if ((i & 1) == 0) {
                        start = Integer.parseInt(input[i]);
                        continue;
                    }

                    list[start].add(Integer.parseInt(input[i]));
                }

                // dfs 돌리기
                Stack<Integer> stack = new Stack<>();

                stack.push(0);
                visit[0] = true;

                int result = 0;
                while (!stack.isEmpty()) {
                    int position = stack.pop();

                    if (position == 99) {
                        result = 1;
                        break;
                    }

                    for (Integer i : list[position]) {
                        if (!visit[i]) {
                            stack.push(i);
                            visit[i] = true;
                        }
                    }
                }

                System.out.println("#" + tc + " " + result);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}