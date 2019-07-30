package boj_9461;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            long[] arr = new long[105];
            arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;
            for(int j=6;j<105;j++){
                arr[j] = arr[j-1]+arr[j-5];
            }

            int tc = Integer.parseInt(br.readLine());
            for(int i=0;i<tc;i++){
                int N = Integer.parseInt(br.readLine());
                sb.append(arr[N]+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}

