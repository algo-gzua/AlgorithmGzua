package solution;

import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		
		for(int m=1;m<tc+1;m++) {
			int h = s.nextInt();
			System.out.println("#" + m);
			int p[][] = new int[11][11];
			
			p[0][0]= 1;	
			for(int i=0; i<h;i++) {
				p[i+1][0]=1;
				System.out.print(p[i+1][0]+ " ");
				for(int j=1;j<i+1;j++) {
					p[i+1][j]=p[i][j-1]+p[i][j];
					System.out.print(p[i+1][j]+ " ");
				}
				System.out.println();
			}
		}
	}
}