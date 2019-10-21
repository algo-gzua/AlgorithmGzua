import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    boolean[] check;

    private void d(int num) {
        int result = num;
        while (num / 10 > 0) {
            result += num % 10;
            num /= 10;
        }

        result += num % 10;

        if (result <= 10000 && !check[result]) {
            check[result] = true;
            d(result);
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            check = new boolean[10001];

            for (int i = 1; i <= 10000; ++i) {
                if (!check[i]) {
                    d(i);
                }
            }

            for (int i = 1; i <= 10000; ++i) {
                if (!check[i]) {
                    System.out.println(i);
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}