import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");

            int N = Integer.parseInt(s[0]);
            int M = Integer.parseInt(s[1]);
            int[] arr = new int[M];

            int left = 1;
            int right = 1;
            for (int i = 0; i < M; ++i) {
                arr[i] = Integer.parseInt(br.readLine());

                right = Math.max(right, arr[i]);
            }

            int result = 0;
            while (left <= right) {
                int mid = (left + right) / 2;

                int count = 0;
                for (int i = 0; i < M; ++i) {
                    count += arr[i] / mid;

                    if (arr[i] % mid != 0) {
                        count++;
                    }
                }

                if (count > N) {
                    left = mid + 1;
                } else {
                    result = mid;
                    right = mid - 1;
                }
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