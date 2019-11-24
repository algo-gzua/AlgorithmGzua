package boj_2872_도서관;

import java.io.*;

public class Main {
    public static void main(String[] arg){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            int[] book = new int[N];

            for(int i=0;i<N;i++){
                int b = Integer.parseInt(br.readLine());
                book[i] = b;
            }

            int cnt = 0;
            int now = N;

            for(int i=N-1;i>=0;i--){
                if(book[i] == now){
                    now = now-1;
                }else{
                    cnt++;
                }
            }

            sb.append(cnt);
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
}