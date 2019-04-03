package solution;

import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		StringBuffer sb = new StringBuffer();
		int tc = s.nextInt();
		for(int i=1;i<tc+1;i++) {
			String input = s.next();
			sb.append(input);
			sb.reverse();
			String c_s = sb.toString();
			System.out.print("#"+i);
			
			if(input.equals(c_s)) {
				System.out.println(" 1");
			}
			else {
				System.out.println(" 0");
			}
			sb.delete(0, sb.toString().length());
			
		}
	}
}
