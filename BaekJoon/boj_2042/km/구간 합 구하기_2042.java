import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String[] s = br.readLine().split(" ");
            int N = Integer.parseInt(s[0]);
            int M = Integer.parseInt(s[1]);
            int K = Integer.parseInt(s[2]);

            int size = 1;

            while (size < N) {
                size <<= 1;
            }

            long[] arr = new long[size * 2];

            // 트리 leaf 생성
            for (int i = size; i < size + N; ++i) {
                arr[i] = Integer.parseInt(br.readLine());
            }

            // 트리 상단부 초기화
            int curr = size;

            while (curr > 1) {
                for (int i = curr; i < curr * 2; i += 2) {
                    arr[i / 2] = arr[i] + arr[i + 1];
                }

                curr /= 2;
            }

            for (int i = 0; i < M + K; ++i) {
                s = br.readLine().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);
                int c = Integer.parseInt(s[2]);

                switch (a) {
                    case 1:
                        // 값 변경
                        int temp = b + size - 1;
                        arr[temp] = c;

                        while (temp > 1) {
                            if (temp % 2 == 0) {
                                arr[temp / 2] = arr[temp] + arr[temp + 1];
                            } else {
                                arr[temp / 2] = arr[temp - 1] + arr[temp];
                            }
                            temp /= 2;
                        }

                        break;
                    case 2:
                        // 구간 합 계산
                        int left = size + b - 1;
                        int right = size + c - 1;

                        long result = 0;
                        while (left < right) {
                            if (left % 2 != 0) {
                                result += arr[left];
                                left++;
                            }
                            if (right % 2 == 0) {
                                result += arr[right];
                                right--;
                            }

                            left /= 2;
                            right /= 2;
                        }

                        if (left == right) {
                            result += arr[left];
                        }

                        System.out.println(result);
                        break;
                    default:
                        break;
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
