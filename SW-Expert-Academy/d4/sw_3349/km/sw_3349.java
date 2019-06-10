import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());

            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                String[] s = br.readLine().split(" ");
//                int W = Integer.parseInt(s[0]);
//                int H = Integer.parseInt(s[1]);
                int N = Integer.parseInt(s[2]);

                String[] temp;

                temp = br.readLine().split(" ");
                int currX = Integer.parseInt(temp[0]);
                int currY = Integer.parseInt(temp[1]);

                int result = 0;
                for (int n = 1; n < N; ++n) {
                    temp = br.readLine().split(" ");

                    int newX = Integer.parseInt(temp[0]);
                    int newY = Integer.parseInt(temp[1]);

                    int diffX = newX - currX;
                    int diffY = newY - currY;

                    // 둘의 부호가 다를 때
                    if (diffX * diffY <= 0) {
                        result += Math.abs(diffX);
                        result += Math.abs(diffY);
                    }
                    // 둘의 부호가 같을 때
                    else {
                        result += Math.min(Math.abs(diffX), Math.abs(diffY));
                        result += Math.abs(diffX - diffY);
                    }

                    currX = newX;
                    currY = newY;
                }

                System.out.println("#" + t + " " + result);

            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}