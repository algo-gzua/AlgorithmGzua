import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            int[] arr;
            String[] s;
            StringBuilder sb = new StringBuilder();

            for (int t = 1; t <= T; ++t) {
                sb.append("#").append(t);

                s = br.readLine().split(" ");
                int N = Integer.parseInt(s[0]);
                int M = Integer.parseInt(s[1]);

                String[] input = br.readLine().split(" ");

                int size = 1;

                while (size < N) {
                    size = size << 1;
                }

                arr = new int[2 * size];

                // 트리의 맨 밑 부분 채우기
                int stringIndex = 0;
                for (int i = size; i < size + N; ++i) {
                    arr[i] = Integer.parseInt(input[stringIndex++]);
                }

                // 트리 윗 부분 채우기
                for (int i = size; i < 2 * size; ++i) {
                    int index = i / 2;

                    while (index > 0) {
                        arr[index] += arr[i];
                        index /= 2;
                    }
                }


                // 명령 수행
                for (int i = 0; i < M; ++i) {
                    String[] query = br.readLine().split(" ");

                    // 값 변경
                    if (Integer.parseInt(query[0]) == 1) {
                        int index = size + Integer.parseInt(query[1]) - 1;

                        int add = Integer.parseInt(query[2]);

                        while (index > 0) {
                            arr[index] += add;

                            index /= 2;
                        }
                    }
                    // 구간 합 계산
                    else {
                        int left = size + Integer.parseInt(query[1]) - 1;
                        int right = size + Integer.parseInt(query[2]) - 1;
                        int sum = 0;

                        while (left < right) {
                            if (left % 2 == 1) {
                                sum += arr[left];
                                left++;
                            }

                            if (right % 2 == 0) {
                                sum += arr[right];
                                right--;
                            }

                            left /= 2;
                            right /= 2;
                        }

                        if (left == right) {
                            sum += arr[left];
                        }

                        sb.append(" ").append(sum);
                    }
                }
                sb.append("\n");
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