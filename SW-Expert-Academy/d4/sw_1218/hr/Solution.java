package solution;

import java.io.*;
import java.util.*;

public class Solution {
	static char top,v;

	public static void main(String[] arg) {
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
			StringBuilder sb = new StringBuilder();
			int res;
			
			for (int i=1;i<=10;i++) {
				int num = Integer.parseInt(br.readLine());
				String str = br.readLine();
				Stack<Character> s = new Stack<Character>();
				
				res = stackPop(str,num,s);
				
				sb.append("#"+i+" "+res+"\n");
			}
			bw.write(sb.toString());
			bw.flush();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	public static int stackPop(String str, int num, Stack<Character> s) {
		char test = str.charAt(0);
		
		s.push(test);
		
		for(int i=1;i<num;i++) {
			v = str.charAt(i);
			if(!s.isEmpty() && s.peek().equals('[') && v==']') { s.pop(); continue; }
			else if(!s.isEmpty() && s.peek().equals('{') && v=='}') { s.pop(); continue; }
			else if(!s.isEmpty() && s.peek().equals('<') && v=='>') { s.pop(); continue; }
			else if(!s.isEmpty() && s.peek().equals('(') && v==')') { s.pop(); continue; }
			else { s.push(v); }
		}
		
		if(s.isEmpty()) { return 1; }
		else { return 0; }
	}
}
