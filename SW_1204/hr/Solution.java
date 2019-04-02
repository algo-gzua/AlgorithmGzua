package solution;
import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		
		for(int i=1;i<tc+1;i++) {
			int m = 0;
			int res = 0;
			int[] score = new int[101];
			
			s.nextInt();
			
			for(int j=0;j<1000;j++) {
				int num = s.nextInt();
				score[num]++;
			}
			
			for(int k=0;k<101; k++) {
				if(score[k]>=m) {
					m = score[k];
					res = k;
				}
			}
			
			System.out.println("#"+i+" "+res);
		}
		s.close();
	}
}
