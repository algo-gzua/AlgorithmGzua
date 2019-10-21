import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");

            int index = 0;
            for (int i = 2; i >= 0; --i) {
                if (s[0].charAt(i) > s[1].charAt(i)) {
                    index = 0;
                    break;
                } else if (s[0].charAt(i) < s[1].charAt(i)) {
                    index = 1;
                    break;
                }
            }

            for (int i = 2; i >= 0; --i) {
                System.out.print(s[index].charAt(i));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}