package boj_2352;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();

            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N];
            ArrayList<Integer> arr2 = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int i=0;i<N;i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }

            arr2.add(arr[0]);
            for(int j=1;j<N;j++){
                if(arr[j]>arr2.get(arr2.size()-1)){
                    arr2.add(arr[j]);
                }else{
                    lowerBound(arr2, arr[j]);
                }
            }
            int res = arr2.size();
            sb.append(res);

            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void lowerBound(ArrayList<Integer> arr2, int target){
        int mid, start,end;
        start = 0;
        end = arr2.size()-1;

        while(start < end){
            mid = (start+end)/2;
            if(target <= arr2.get(mid)){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        arr2.set(end,target);
    }
}
