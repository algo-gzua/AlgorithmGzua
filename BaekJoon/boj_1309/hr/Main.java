package boj_1309;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N+1];
            arr[0]=1; arr[1] = 3;
            for(int i=2;i<=N;i++){
                arr[i] = (arr[i-1]*2 + arr[i-2])%9901;
            }
            sb.append(arr[N]);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
