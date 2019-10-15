package boj_10039;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            int sum = 0;
            for(int i=0;i<5;i++){
                int score = Integer.parseInt(br.readLine());
                if(score>=40){
                    sum += score;
                }else{
                    sum += 40;
                }
            }
            sum = sum/5;
            sb.append(sum);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
