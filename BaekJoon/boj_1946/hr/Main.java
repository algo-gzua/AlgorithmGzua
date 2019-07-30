package boj_1946;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int tc = Integer.parseInt(br.readLine());
            for(int i=0;i<tc;i++) {
                int cnt = 1;
                int N = Integer.parseInt(br.readLine());
                int[][] arr = new int[N][2];
                for (int j = 0; j < N; j++) {
                    st = new StringTokenizer(br.readLine());
                    arr[j][0] = Integer.parseInt(st.nextToken());
                    arr[j][1] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(arr, new Comparator<int[]>(){
                    @Override
                    public int compare(int[] arr1, int[] arr2){
                        if(((Comparable)arr1[0]).compareTo(arr2[0])<0)
                            return -1;
                        else
                            return 1;
                    }
                });
                int cmp = arr[0][1];
                for(int k=1;k<N;k++){
                    if(arr[k][1]<cmp){
                        cnt++;
                        cmp = arr[k][1];
                    }
                }
                sb.append(cnt+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
