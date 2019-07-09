package boj_2217;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            int rope  = Integer.parseInt(br.readLine());
            Integer[] arr = new Integer[rope];
            for(int j=0;j<rope;j++){
                arr[j] = Integer.parseInt(br.readLine());
            }
            int res = 0;
            int cnt = 1;
            Arrays.sort(arr, Comparator.reverseOrder());
            for (int i=0;i<rope;i++){
                int w = arr[i]*cnt;
                if(res < w){
                    res = w;
                }
                cnt++;
            }
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
