package boj_9095;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int tc = Integer.parseInt(br.readLine());
            int[] arr = new int[100];
            arr[0] = 0;
            arr[1] = 1;
            arr[2] = 2;
            arr[3] = 4;
            for (int i=0;i<tc;i++){
                int n = Integer.parseInt(br.readLine());
                for(int j=4;j<=n;j++){
                    arr[j] = arr[j-1] + arr[j-2] + arr[j-3];
                }
                sb.append(arr[n]+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
