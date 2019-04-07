import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());

            HashMap<String, Integer> map = new HashMap<>();

            map.put("0001101", 0);
            map.put("0011001", 1);
            map.put("0010011", 2);
            map.put("0111101", 3);
            map.put("0100011", 4);
            map.put("0110001", 5);
            map.put("0101111", 6);
            map.put("0111011", 7);
            map.put("0110111", 8);
            map.put("0001011", 9);

            String[] nm;
            int N, M;
            String compare = "";
            StringBuilder zero;
            ArrayList<Integer> list = new ArrayList<>();

            int backIndex;

            for (int t = 1; t <= T; ++t) {
                nm = br.readLine().split(" ");
                N = Integer.parseInt(nm[0]);
                M = Integer.parseInt(nm[1]);

                zero = new StringBuilder();
                list.clear();
                for (int m = 0; m < M; ++m) {
                    zero.append("0");
                }

                String s;
                for (int n = 0; n < N; ++n) {
                    s = br.readLine();

                    if (!s.equals(zero.toString())) {
                        compare = s;
                    }
                }

                backIndex = 0;
                for (int i = M - 1; i >= 0; --i) {
                    if (compare.charAt(i) == '1') {
                        backIndex = i;
                        break;
                    }
                }

                StringBuilder temp;
                while (backIndex >= 6) {
                    temp = new StringBuilder();
                    for (int i = backIndex; i > backIndex - 7; --i) {
                        temp.insert(0, compare.charAt(i));
                    }

                    if (temp.toString().equals("0000000")) {
                        break;
                    }

                    list.add(map.get(temp.toString()));

                    backIndex -= 7;
                }

                Collections.reverse(list);

                int listSize = list.size();

                int odd = 0;
                int even = 0;
                int code = 0;

                // 0번 index가 1번으로 생각
                // 0번 index는 홀수
                for (int i = 0; i < listSize; ++i) {
                    if (i == listSize - 1) {
                        code = list.get(i);
                    } else if (i % 2 == 0) {
                        odd += list.get(i);
                    } else {
                        even += list.get(i);
                    }
                }

                if ((odd * 3 + even + code) % 10 == 0) {
                    System.out.println("#" + t + " " + (odd + even + code));
                } else {
                    System.out.println("#" + t + " 0");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
