package boj_5545_최고의피자;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(br.readLine());
            Integer[] topping = new Integer[N];
            int cal = C;
            int max = cal/A;

            for(int i=0;i<N;i++){
                topping[i] = Integer.parseInt(br.readLine());
            }
            Arrays.sort(topping,Collections.reverseOrder());
            for(int i=0;i<N;i++){
                int price = A + B*(i+1);
                cal += topping[i];
                int res = cal/price;
                max = Math.max(max,res);
            }
            sb.append(max);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
