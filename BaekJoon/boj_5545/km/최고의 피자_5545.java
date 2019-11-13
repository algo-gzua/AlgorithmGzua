import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int N = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            int kcal = Integer.parseInt(br.readLine());
            int price = A;
            int result = kcal / price;

            int[] arr = new int[N];
            for (int i = 0; i < N; ++i) {
                arr[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(arr);

            for (int i = N - 1; i >= 0; --i) {
                kcal += arr[i];
                price += B;

                if (result <= kcal / price) {
                    result = kcal / price;
                } else {
                    break;
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