package solution;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] arg) {
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
			
			int tc=Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder();
			
			for (int i=1;i<=tc;i++){
				StringTokenizer st = new StringTokenizer(br.readLine());
				int studentNum = Integer.parseInt(st.nextToken());
				int sibmitNum = Integer.parseInt(st.nextToken());
				int[] check = new int[studentNum+1];
				int student;
				StringTokenizer st2 = new StringTokenizer(br.readLine());
				
				//제출한 학생의 배열에 1입력 (인덱스==학생번호)
				for(int j=1; j<=sibmitNum;j++){
					student = Integer.parseInt(st2.nextToken());
					check[student]=1;
				}
				sb.append("#").append(i);
				
				//배열값이 0이면 미제출이므로 배열의 인덱스(==학생번호) 출력
				for(int k=1;k<=studentNum;k++){
		            if(check[k]==0){
		               sb.append(" ").append(k);
		            }
		         }
				sb.append("\n");
			}
			bw.write(sb.toString());
			bw.flush();
		}catch(IOException e) {
			e.printStackTrace();
		}
	
	}
}