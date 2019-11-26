package boj_1477_휴게소세우기;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); //현재 휴게소의 개수
            int M = Integer.parseInt(st.nextToken()); //더 지을 휴게소의 개수
            int L = Integer.parseInt(st.nextToken()); //고속도로의 길이
            int[] road = new int[N+2];
            int left = 0;
            int right = L;
            int mid = 0;
            int max = 0;

            st = new StringTokenizer(br.readLine());
            for(int i=1;i<N+1;i++){
                road[i] = Integer.parseInt(st.nextToken());
            }
            road[N+1] = L;

            Arrays.sort(road);

            while(left<=right){
                mid = (left + right) / 2;
                int cnt = 0;

                for(int i=1;i<=N+1;i++){
                    cnt += (road[i]-road[i-1]-1)/mid;
                }

                if(cnt > M){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            sb.append(left);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
