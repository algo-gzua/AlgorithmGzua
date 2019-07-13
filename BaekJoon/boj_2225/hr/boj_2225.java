package boj_2225;

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
            int[][] arr = new int[N+1][K+1];
            for (int[] row: arr)
                Arrays.fill(row, 1);

            for(int i=1;i<=N;i++){
                for(int j=2;j<=K;j++){
                    arr[i][j] = (arr[i][j-1]+arr[i-1][j]) % 1000000000;
                }
            }
            sb.append(arr[N][K]);
            bw.write(sb.toString());
            bw.flush();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
