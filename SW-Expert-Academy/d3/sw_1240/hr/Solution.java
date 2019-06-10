package solution;
import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for(int i=1;i<tc+1;i++) {
			int height = s.nextInt();
			int length = s.nextInt();
			int res = 0;
			String code = null;
			int[] arr = new int[8];
			for(int j=0; j<height; j++) {
				String input = s.next();
				if(input.contains("1")) {
					code = input;
				}
			}
			int last = code.lastIndexOf('1')+1;
			int cnt = 7;
			for(int k=0;k<8;k++) {
				String splitCode = code.substring(last-(7*(k+1)),last-(7*k));
				switch(splitCode) {
				case "0001101":
					arr[cnt] = 0;
					break;
				case "0011001":
					arr[cnt] = 1;
					break;
				case "0010011":
					arr[cnt] = 2;
					break;
				case "0111101":
					arr[cnt] = 3;
					break;
				case "0100011":
					arr[cnt] = 4;
					break;
				case "0110001":
					arr[cnt] = 5;
					break;
				case "0101111":
					arr[cnt] = 6;
					break;
				case "0111011":
					arr[cnt] = 7;
					break;
				case "0110111":
					arr[cnt] = 8;
					break;
				case "0001011":
					arr[cnt] = 9;
					break;
					
				}
				cnt--;
			}
			int testCode = (arr[0]+arr[2]+arr[4]+arr[6])*3 
					+arr[1]+arr[3]+arr[5]+arr[7];
			if(testCode%10 == 0) {
				for(int l=0;l<8;l++) {
					res+=arr[l];
				}
				System.out.println("#"+i+" "+res);
			}
			else {
				System.out.println("#"+i+" 0");
			}
		}
	}
}
