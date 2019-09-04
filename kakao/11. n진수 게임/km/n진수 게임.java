
public class Solution {

	// n: 진법 
	// t: 미리 구할 숫자의 개수
	// m: 게임에 참가하는 인원
	// p: 튜브의 순서
	public String solution(int n, int t, int m, int p) {
		String answer = "";
		int len = t * m;
		int curr = 0;
		
		String s = "";
		while (s.length() < len) {
			s += Integer.toString(curr++, n).toUpperCase();
		}
		
		int index = p - 1;
		while (answer.length() < t) {
			answer += s.charAt(index);
			index += m;
		}
		
		if (answer.length() != t) { 
			answer.substring(0, t);
		}
		
		return answer;
	}
	
	public static void main(String[] args) {
		System.out.println(new Solution().solution(2, 4, 2, 1));
	}
}
