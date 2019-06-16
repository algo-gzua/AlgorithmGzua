package sw_3752;

import java.io.*;
import java.util.*;

public class Solution {
    static int[] score;
    static int N;
    static boolean[] check;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int tc = Integer.parseInt(br.readLine());
            for(int i=1; i<=tc; i++){
                N = Integer.parseInt(br.readLine());
                st = new StringTokenizer(br.readLine());

                score = new int[101];
                check = new boolean[10002];
                for(int j=0;j<N;j++){
                    score[j] = Integer.parseInt(st.nextToken());
                }

                check[0] = true;
                for(int k=0;k<N;k++){
                    for(int m=10001;m>=0;m--){
                        if(check[m]){
                            check[m+score[k]] = true;
                        }
                    }
                }

                int cnt=0;
                for (int l=0;l<10001;l++){
                    if(check[l]){
                        cnt++;
                    }
                }
                sb.append("#"+i+" "+cnt+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}