package boj_1049;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); //기타줄개수
            int M = Integer.parseInt(st.nextToken()); //브랜드개수

            int[] set = new int[M];
            int[] piece = new int[M];
            int res = 0; int s = 0; int p = 0;
            int set_number = N/6;

            for(int j=0;j<M;j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()); //패키지
                int b = Integer.parseInt(st.nextToken()); //낱개
                set[j] = a;
                piece[j] = b;
            }

            Arrays.sort(set);
            Arrays.sort(piece);

            if(N > 6 && N%6 == 0){
                res = Math.min(set[0]*set_number,piece[0]*N);
            }else if(N > 6 && N%6 != 0){
                res = Math.min(set[0]*(set_number+1),
                        (set[0]*set_number)+piece[0]*(N-(set_number*6)));
                res = Math.min(res,piece[0]*N);
            }else{
                res = Math.min(set[0],piece[0]*N);
            }
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
