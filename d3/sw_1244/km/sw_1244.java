import java.io.*;

public class Solution {
    int result;

    private void recursion(char[] number, int count) {
        if (count == 0) {
            if (result < Integer.parseInt(String.valueOf(number))) {
                result = Integer.parseInt(String.valueOf(number));
            }
            return;
        }

        char[] temp;
        int size = number.length;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (number[i] <= number[j]) {
                    temp = number.clone();

                    char tempChar = temp[i];
                    temp[i] = temp[j];
                    temp[j] = tempChar;

                    recursion(temp, count - 1);
                }
            }
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());
            StringBuilder sb = new StringBuilder();

            String[] s;
            int count;
            for (int t = 1; t <= T; ++t) {
                s = br.readLine().split(" ");
                result = 0;

                count = Integer.parseInt(s[1]);

                recursion(s[0].toCharArray(), count);

                sb.append("#").append(t).append(" ").append(result).append("\n");
            }

            bw.write(sb.toString());
            bw.flush();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
