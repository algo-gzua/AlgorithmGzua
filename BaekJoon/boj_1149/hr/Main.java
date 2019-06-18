package boj_1149;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] arr;
    static int res = 1000001;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            N = Integer.parseInt(br.readLine());
            arr = new int[N][3];

            for(int i=0;i<N;i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0;j<3;j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for(int k=0;k<3;k++){
                detect(k,arr[0][k],1);
            }
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();

        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void detect(int index, int max, int a){

        if(a == N){
            res = Math.min(max,res);
            return;
        }

        for(int i=0;i<3;i++){
            if(i != index && a != N){
                detect(i, max+arr[a][i],a+1);
            }
        }
    }
}
