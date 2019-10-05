import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String s = br.readLine().toUpperCase();

            int[] arr = new int[26];

            for (int i = 0; i < s.length(); ++i) {
                arr[s.charAt(i) - 'A']++;
            }

            int index = 0;
            for (int i = 0; i < arr.length; ++i) {
                if (arr[index] < arr[i]) {
                    index = i;
                }
            }

            for (int i = 0; i < arr.length; ++i) {
                if (i != index && arr[index] == arr[i]) {
                    System.out.println("?");
                    return;
                }
            }

            System.out.println((char)(index + 'A'));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}