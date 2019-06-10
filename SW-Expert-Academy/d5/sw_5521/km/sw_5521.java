import java.io.*;
import java.util.ArrayList;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());

            String[] s;
            StringBuilder sb = new StringBuilder();
            boolean[] isReceive;
            for (int t = 1; t <= T; ++t) {
                s = br.readLine().split(" ");
                int N = Integer.parseInt(s[0]);
                int M = Integer.parseInt(s[1]);

                ArrayList<Integer>[] arrayList = new ArrayList[N + 1];
                isReceive = new boolean[N + 1];

                for (int n = 0; n <= N; ++n) {
                    arrayList[n] = new ArrayList<>();
                }

                for (int m = 1; m <= M; ++m) {
                    s = br.readLine().split(" ");
                    int a = Integer.parseInt(s[0]);
                    int b = Integer.parseInt(s[1]);

                    arrayList[a].add(b);
                    arrayList[b].add(a);
                }

                int result = 0;
                isReceive[1] = true;

                if (arrayList[1].size() != 0) {
                    int size = arrayList[1].size();

                    for (int i = 0; i < size; ++i) {
                        if (!isReceive[arrayList[1].get(i)]) {
                            result++;
                            isReceive[arrayList[1].get(i)] = true;
                        }

                        // 1이 준애의 리스트를 순회
                        for (Integer a : arrayList[arrayList[1].get(i)]) {
                            if (isReceive[a]) {
                                continue;
                            }

                            result++;
                            isReceive[a] = true;
                        }
                    }
                }

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
