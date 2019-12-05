import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    private void solve() {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N + 2];

            for (int i = 1; i <= N; ++i) {
                arr[i] = Integer.parseInt(br.readLine());
            }

            Stack<Integer> stack = new Stack<>();
            stack.push(0);

            int result = 0;
            for (int n = 1; n <= N + 1; ++n) {
                while (!stack.isEmpty() && arr[stack.peek()] > arr[n]) {
                    int item = stack.pop();

                    int position = n - stack.peek() - 1;

                    result = Math.max(result, arr[item] * position);
                }

                stack.push(n);
            }

            System.out.println(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}
