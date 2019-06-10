package solution;
import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for(int i=1;i<tc+1;i++) {
			String input = s.next();
			String i_c = s.next();
			String res = "";
			String res2="";

			res = Compare(input,res);
			res2 = Compare(i_c,res2);
			
			if(res.equals(res2)) {
				System.out.println("#"+i+" SAME");
			}
			else {
				System.out.println("#"+i+" DIFF");
			}
		}
	}
	public static String Compare(String input, String res ) {
		for(int i=0; i<input.length(); i++) {
			char x = input.charAt(i);
			if(x == 'A' || x=='D' || x=='O' || x=='P' || x=='Q'|| x=='R') {
				res = res.concat("1");
			}
			else if(x == 'B') {
				res = res.concat("2");
			}
			else {
				res = res.concat("0");
			}
		}
		return res;
	}
}
