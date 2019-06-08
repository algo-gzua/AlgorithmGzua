package sw_3503;

import java.io.*;
import java.util.ArrayDeque;
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
            for (int i=1;i<=tc;i++){
                int N = Integer.parseInt(br.readLine());
                st = new StringTokenizer(br.readLine());
                Integer[] pong = new Integer[N];
                ArrayDeque<Integer> deque = new ArrayDeque<Integer>(N);

                for(int j=0;j<N;j++){
                    pong[j] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(pong, Collections.reverseOrder());

                for(int k=0;k<N;k++){
                    if (k%2 == 0){
                        deque.add(pong[k]);
                    }
                    else{
                        deque.push(pong[k]);
                    }
                }
                int x = 0;
                int[] test = new int[N];
                for (Integer number : deque) {
                    test[x] = number;
                    x++;
                    //System.out.println("Number = " + number);
                }
                int cmp = Math.abs(test[0]-test[1]);
                int cmp2;
                for(int l=1;l<N-1;l++){
                    cmp2 = Math.abs(test[l]-test[l+1]);
                    cmp = Math.max(cmp,cmp2);
                }

                sb.append("#"+i+" "+ cmp +"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
