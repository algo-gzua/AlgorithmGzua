package boj_11586_민균이의계략;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            LinkedList<Integer> num = new LinkedList<>();
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            num.add(Integer.parseInt(st.nextToken()));

            for(int i=0;i<N-1;i++){
                int input = Integer.parseInt(st.nextToken());

                if(num.get(num.size()-1) < input){
                    num.add(input);
                }else{
                    LIS(input, num);
                }
            }
            sb.append(num.size());
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static void LIS(int input, LinkedList num){
        int start = 0; int mid = 0;
        int end = num.size()-1;

        while(start < end){
            mid = (start+end) / 2;
            if(input <= Integer.parseInt(num.get(mid).toString())){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        num.set(end, input);
    }
}
