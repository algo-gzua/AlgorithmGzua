package solution;

import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		
		for(int i=1;i<tc+1;i++) {
			int day = s.nextInt();
			long[] exp = new long[day];
			long max = 0;
			long res = 0;
			for(int j=0; j<day; j++) {
				exp[j] = s.nextInt();
			}
			for(int k=day-1;k>=0;k--) {
				if(exp[k] < max) {
					res += max-exp[k];
				}
				else  {
					max = exp[k];
				}
			}
			System.out.println("#"+i+" "+res);
		}
		s.close();
	}
}
