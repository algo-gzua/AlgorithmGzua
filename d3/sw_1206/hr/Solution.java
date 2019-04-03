package solution;
import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		//int tc = s.nextInt();

		for(int i=1;i<11;i++) {
			int cnt = s.nextInt();
			int[] building = new int[cnt];
			int res=0;
			int res2 = 0;
			for(int j=0;j<cnt;j++) {
				building[j]=s.nextInt();
			}
			
			for(int k=2;k<cnt-2;k++) {
					int left = getMax(building[k-1],building[k-2]);
					int right = getMax(building[k+1],building[k+2]);
					int max = getMax(left,right);
					res2 = building[k]-max;
					if(res2>0) {
						res = res+res2;
					}
			}
			System.out.println("#"+i+" "+res);
		}
	}
	private static int getMax(int first, int second) {
		return first >= second ? first : second;
	}
}
