import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Solution {
    public int[] solution(String msg) {
        int[] answer = {};
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 'A'; i <= 'Z'; ++i) {
            map.put(String.valueOf((char)i), i - 65 + 1);
        }
        int nextIndex = 27;

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < msg.length(); ++i) {
            String temp = String.valueOf(msg.charAt(i));
            int printNumber = map.get(temp);
            for (int j = i + 1; j < msg.length(); ++j) {
                temp += msg.charAt(j);

                if (map.containsKey(temp)) {
                    printNumber = map.get(temp);
                    i += j - i;
                } else {
                    map.put(temp, nextIndex++);
                    break;
                }
            }
            list.add(printNumber);
        }

        answer = new int[list.size()];

        for (int i = 0; i < list.size(); ++i) {
            answer[i] = list.get(i);
        }

        return answer;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution().solution("TOBEORNOTTOBEORTOBEORNOT")));
    }
}
