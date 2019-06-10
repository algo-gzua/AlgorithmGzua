package date_190516.sw_1219;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int result = 0;
    static int[] arr;
    static int[] arr2;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            StringTokenizer st;

            for (int i=1;i<=10;i++){
                st = new StringTokenizer(br.readLine());
                int tc = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());
                arr = new int[100];
                arr2 = new int[100];
                int index = 0;
                result = 0;

                st = new StringTokenizer(br.readLine());

                for(int j=0;j<n*2;j++){
                    if(j%2==1){
                        if(arr[index]==0) {
                            arr[index] = Integer.parseInt(st.nextToken());
                        }else{
                            arr2[index] = Integer.parseInt(st.nextToken());
                        }
                    }else{
                        index = Integer.parseInt(st.nextToken());
                    }
                }
                dfs(0);
                sb.append("#"+tc+" "+result+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    static int dfs(int now) {

        if(arr[now] == 0){
            return 0;
        }

        if(arr[now]==99||arr2[now]==99) {
            result = 1;
            return result;
        }

        if(arr[now]!=0){
            dfs(arr[now]);
            if(result == 1){
                return 0;
            }
        }

        if(arr2[now]!=0){
            dfs(arr2[now]);
            if(result ==1 ){
                return 0;
            }
        }
        return 0;
    }
}
