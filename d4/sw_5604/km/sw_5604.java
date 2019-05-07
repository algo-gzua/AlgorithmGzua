import java.io.*;

public class Solution {
    long[] counts;
    long positionNumber;

    private void countNumber(long num) {
        while (num > 0) {
            int index = (int)(num % 10);
            counts[index] += positionNumber;
            num /= 10;
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine(), 10);

            String[] s;
            for (int t = 1; t <= T; ++t) {
                counts = new long[10];

                s = br.readLine().split(" ");
                long A = Long.parseLong(s[0], 10);
                long B = Long.parseLong(s[1], 10);

                long result = 0;
                positionNumber = 1;
                boolean isSame = false;
                while (true) {
                    // A는 0으로, B는 9로 만들기
                    while (A % 10 != 0) {
                        if (A == B) {
                            isSame = true;
                            break;
                        }

                        countNumber(A);
                        A++;
                    }

                    while (B % 10 != 9) {
                        if (A == B) {
                            isSame = true;
                            break;
                        }

                        countNumber(B);
                        B--;
                    }

                    // 같다면 계산하고 탈출
                    if (isSame) {
                        countNumber(A);
                        break;
                    }

                    // 중간 숫자 만들기
                    long count = (B / 10) - (A / 10) + 1;

                    count *= positionNumber;
                    positionNumber *= 10;

                    for (int i = 1; i <= 9; ++i) {
                        counts[i] += count;
                    }

                    // 다음 자리수 탐색
                    A /= 10;
                    B /= 10;
                }

                // 결과 출력
                for (int i = 1; i <= 9; ++i) {
                    result += (i * counts[i]);
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