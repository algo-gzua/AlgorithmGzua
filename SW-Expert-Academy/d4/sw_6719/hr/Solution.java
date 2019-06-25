package sw_6719;

import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;

            int tc = Integer.parseInt(br.readLine());

            for(int i=1; i<=tc; i++){
                st = new StringTokenizer(br.readLine());
                int N = Integer.parseInt(st.nextToken());
                int M = Integer.parseInt(st.nextToken());

                st = new StringTokenizer(br.readLine());
                Integer[] arr = new Integer[N];

                for(int j=0;j<N;j++){
                    arr[j] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(arr, Collections.reverseOrder());
                double res = 0;
                for(int k=M-1;k>=0;k--){
                    res = ( res + arr[k] ) / 2;
                }
                sb.append("#"+i+" "+res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
