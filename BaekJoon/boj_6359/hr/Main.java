package boj_6359;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int tc = Integer.parseInt(br.readLine());

            for(int i=0;i<tc;i++){
                int n = Integer.parseInt(br.readLine());
                int cnt = 0;
                boolean[] room = new boolean[n+1];
                for(int j=2;j<=n;j++){
                    for(int k=1;k*j<=n;k++){
                        if(!room[j*k]){
                            room[j*k] = true;
                        }else{
                            room[j*k] = false;
                        }
                    }
                }
                for(int l=1;l<=n;l++){
                    if(!room[l]) cnt++;
                }
                sb.append(cnt+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
