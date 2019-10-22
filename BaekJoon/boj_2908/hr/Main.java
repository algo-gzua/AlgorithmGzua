package boj_2908_상수;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] arg){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            a = Integer.parseInt(sb.append(a).reverse().toString());
            sb.delete(0,sb.length());
            b = Integer.parseInt(sb.append(b).reverse().toString());
            sb.delete(0,sb.length());

            if(a > b){
                sb.append(a);
            }else{
                sb.append(b);
            }

            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
