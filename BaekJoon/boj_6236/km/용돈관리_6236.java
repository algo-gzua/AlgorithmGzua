import java.io.*;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");
            int N = Integer.parseInt(s[0]);
            int M = Integer.parseInt(s[1]);
            int[] arr = new int[N];
            int sum = 0;

            for (int i = 0; i < N; ++i) {
                arr[i] = Integer.parseInt(br.readLine());
                sum += arr[i];
            }

            int left = 0;
            int right = sum;
            int result = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                int count = 0;
                int currMoney = 0;

                for (int i = 0; i < N; ++i) {
                    if (currMoney - arr[i] >= 0) {
                        currMoney -= arr[i];
                    } else {
                        currMoney = mid;
                        count++;
                        i--;
                    }

                    if (count > M) {
                        break;
                    }
                }

                if (count > M) {
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