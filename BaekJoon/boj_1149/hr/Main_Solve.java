package boj_1149;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            int[][] arr = new int[N][3];
            for(int i=0;i<N;i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0;j<3;j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int[][] RGB = new int[N][3];

            for(int k=0;k<3;k++){
                RGB[0][k] = arr[0][k];
            }
            for(int l=0;l<N-1;l++){
                RGB[l+1][0] = Math.min(RGB[l][1],RGB[l][2]) + arr[l+1][0];
                RGB[l+1][1] = Math.min(RGB[l][0],RGB[l][2]) + arr[l+1][1];
                RGB[l+1][2] = Math.min(RGB[l][0],RGB[l][1]) + arr[l+1][2];
            }
            int res = Math.min(RGB[N-1][0],RGB[N-1][1]);
            res = Math.min(res,RGB[N-1][2]);
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
