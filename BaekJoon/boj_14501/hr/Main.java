package boj_14501;

import java.io.*;
import java.util.*;

public class Main {
    static int[][] arr;
    static int day;
    static int res=0;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            day = Integer.parseInt(br.readLine());
            arr = new int[2][day+1];

            for(int i=1;i<=day;i++){
                st = new StringTokenizer(br.readLine());
                arr[0][i] = Integer.parseInt(st.nextToken());
                arr[1][i] = Integer.parseInt(st.nextToken());
            }
            dfs(1,0);
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();

        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void dfs(int start,int pay){
        if(start == day+1){
            res = Math.max(res,pay);
            return;
        }
        if(start + arr[0][start] <= day+1){
            dfs(start+arr[0][start], pay+arr[1][start]);
        }
        dfs(start+1,pay);
    }
}
