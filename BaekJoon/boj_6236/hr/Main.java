package boj_6236;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int[] money = new int[N];
            int left=0;
            int right = 0;
            int mid;
            int cnt = 1;
            int min = 1;

            for(int i=0;i<N;i++){
                money[i] = Integer.parseInt(br.readLine());
                left = Math.max(left, money[i]);
                right += money[i];
            }

            while(left<=right){
                mid = (left + right) / 2;
                int balance = mid;
                cnt = 1;

                for(int i=0;i<N;i++){
                    balance -= money[i];
                    if(balance < 0){
                        cnt++;
                        balance = mid;
                        balance -= money[i];
                    }

                    if(balance == 0){
                        balance = mid;
                        if (i < N - 1) {
                            cnt++;
                        }
                    }
                }

                if(cnt > M){
                    left = mid+1;
                } else {
                    min = mid;
                    right = mid-1;
                }

            }

            sb.append(min);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
