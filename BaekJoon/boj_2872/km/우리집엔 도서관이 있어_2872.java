import java.io.*;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N];

            for (int i = 0; i < N; ++i) {
                arr[i] = Integer.parseInt(br.readLine());
            }

            int result = N;

            for (int i = N - 1; i >= 0; --i) {
                if (result == arr[i]) {
                    result--;
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