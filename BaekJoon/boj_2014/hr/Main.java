package boj_2014;

import java.io.*;
import java.util.*;

public class Main {public static void main(String[] args) {
    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> prq = new PriorityQueue<>();
        int[] num = new int[K];

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<K;i++){
            int x = Integer.parseInt(st.nextToken());
            num[i] = x;
            prq.add(x);
        }
        for(int j=0;j<N-1;j++){
            int u = prq.poll();
            for(int k=0;k<K;k++){
                prq.add(u*num[k]);

                if(u%num[k] == 0) break;
            }
        }

        sb.append(prq.poll());
        bw.write(sb.toString());
        bw.flush();

    }catch(Exception e){
        e.printStackTrace();
    }
}

}
