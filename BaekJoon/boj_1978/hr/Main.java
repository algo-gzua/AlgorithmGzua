package boj_1978;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int size = 1002;
    static boolean[] arr = new boolean[size+5];
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();

            arrInit();

            int tc = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cnt = 0;

            for(int i=0;i<tc;i++){
                int x = Integer.parseInt(st.nextToken());
                if(!arr[x]){
                    cnt++;
                }
            }

            sb.append(cnt);

            bw.write(sb.toString());
            bw.flush();

        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void arrInit(){
        arr[0] = arr[1] = true;
        for(int i=2;i<size;i++){
            for(int j=2;j<=size/i;j++){
                arr[i*j]=true;
            }
        }
    }
}

