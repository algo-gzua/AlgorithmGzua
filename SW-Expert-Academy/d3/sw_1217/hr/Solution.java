package date_190424.sw_1217;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int cnt=1;
    static int Num;
    static int res;
    public static void main(String[] args){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int N,M;

            for(int i=0;i<10;i++){
                int tc = Integer.parseInt(br.readLine());
                st = new StringTokenizer(br.readLine());
                N = Integer.parseInt(st.nextToken());
                M = Integer.parseInt(st.nextToken());
                Num = N;
                res = 0;
                square(N,M);
                sb.append("#"+tc+" "+res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(IOException e) {
            e.printStackTrace();
        }
    }
    public static void square(int N, int M){
        if(cnt != M){
            res = N*Num;
            cnt++;
            square(res,M);
        }
        else if(cnt == M) {
            cnt = 1;
        }
    }
}
