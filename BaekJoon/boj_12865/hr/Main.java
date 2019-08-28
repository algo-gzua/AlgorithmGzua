package boj_12865;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            int[] W = new int[N+1];
            int[] V = new int[N+1];
            int[][] m = new int[N+1][1000001];

            for(int i=1;i<=N;i++){
                st = new StringTokenizer(br.readLine());
                W[i] = Integer.parseInt(st.nextToken());
                V[i] = Integer.parseInt(st.nextToken());
            }
            for(int j=1; j<=N; j++){
                for(int k=1; k<=K; k++){
                    m[j][k] = m[j-1][k];
                    if(k-W[j] >= 0){
                        m[j][k] = Math.max(m[j][k], m[j-1][ k - W[j] ] + V[j]);
                    }
                }
            }
            sb.append(m[N][K]);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
