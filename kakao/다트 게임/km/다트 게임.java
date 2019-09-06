import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
	private int pow(int number, int count) {
        int result = 1;
        for (int i = 0; i < count; ++i) {
            result *= number;
        }

        return result;
    }
	
    public int solution(String dartResult) {
        int answer = 0;
        ArrayList<Integer> list = new ArrayList<>();

        int currentIndex = -1;
        for (int i = 0; i < dartResult.length(); ++i) {
        	if (dartResult.charAt(i) == '1' && dartResult.charAt(i + 1) == '0') {
        		list.add(10);
        		currentIndex++;
        		i++;
        	} else if (dartResult.charAt(i) >= '0' && dartResult.charAt(i) <= '9') {
                list.add(dartResult.charAt(i) - '0');
                currentIndex++;
            } else if (dartResult.charAt(i) == 'S') {
                continue;
            } else if (dartResult.charAt(i) == 'D') {
                list.set(currentIndex, pow(list.get(currentIndex), 2));
            } else if (dartResult.charAt(i) == 'T') {
                list.set(currentIndex, pow(list.get(currentIndex), 3));
            } else if (dartResult.charAt(i) == '#') {
                list.set(currentIndex, list.get(currentIndex) * -1);
            } else if (dartResult.charAt(i) == '*') {
                if (currentIndex == 0) {
                    list.set(currentIndex, list.get(currentIndex) * 2);
                } else {
                    list.set(currentIndex, list.get(currentIndex) * 2);
                    list.set(currentIndex - 1, list.get(currentIndex - 1) * 2);
                }
            }
        }

        for (int i : list) {
            answer += i;
        }

        return answer;
    }
	
	public static void main(String[] args) {
		System.out.println(new Solution().solution("1D2S#10S"));
	}
}