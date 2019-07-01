package boj_1965;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();

            int tc = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int[] arr = new int[tc];
            ArrayList<Integer> arr2 = new ArrayList<>();

            for(int i=0;i<tc;i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }

            arr2.add(arr[0]);
            for(int j=1;j<tc;j++){
                if(arr[j]>arr2.get(arr2.size()-1)){
                    arr2.add(arr[j]);
                }else{
                    LowerBound(arr2,arr[j]);
                }

            }
            sb.append(arr2.size());
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void LowerBound(ArrayList<Integer> arr2, int target){
        int start = 0;
        int end = arr2.size()-1;
        int mid;

        while(start<end){
            mid = (start+end)/2;
            if( target <= arr2.get(mid) ){
                end = mid;
            }else{
                start = mid+1;
            }

        }
        arr2.set(start, target);
    }
}
