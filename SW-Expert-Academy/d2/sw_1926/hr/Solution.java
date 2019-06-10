package solution;

import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		String s_i;
		for(int i=1; i<=num ; i++) {
			s_i = Integer.toString(i);
			int res = getCharNumber(s_i,'3','6','9');
			if(res == 0) {
				System.out.print(i+" ");
			}
			else {
				for(int j=0;j<res;j++) {
					System.out.print("-");
				}
				System.out.print(" ");
			}
		}
	}
	public static int getCharNumber(String str, char a, char b, char c) {
		int cnt = 0;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)== a || str.charAt(i)== b || str.charAt(i)== c ) {
				cnt++;
			}
		}
		return cnt;
	}
}
