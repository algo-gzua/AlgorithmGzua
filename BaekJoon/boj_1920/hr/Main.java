package boj_1920;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N];

            st = new StringTokenizer(br.readLine());
            for(int i=0;i<N;i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);

            int M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++){
                int target = Integer.parseInt(st.nextToken());
                int res = BinarySearch(arr,target);
                sb.append(res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.getStackTrace();
        }
    }
    static int BinarySearch(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        int mid;
        while(start<end){
            mid = (start + end) / 2;
            if(target <= arr[mid]){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        if(arr[start] == target) return 1;
        else return 0;
    }
}
