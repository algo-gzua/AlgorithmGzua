package sw_1247;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int customer;
    static int[][] arr;
    static boolean[] visited;
    static int res=10000;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int tc = Integer.parseInt(br.readLine());
            StringTokenizer st;

            for(int i=1;i<=tc;i++){
                res=10000;
                customer = Integer.parseInt(br.readLine());
                arr = new int[customer+2][2];
                st = new StringTokenizer(br.readLine());

                for(int j=0;j<customer+2;j++){
                    arr[j][0] = Integer.parseInt(st.nextToken());
                    arr[j][1] = Integer.parseInt(st.nextToken());
                }
                visited = new boolean[customer+2];
                detect(0,customer,0,0);
                sb.append("#"+i+" "+res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void detect(int k,int customer, int len,int before){
        int distance = 0;
        if(k == customer) {
            len += Math.abs(arr[1][0]-arr[before][0]) + Math.abs(arr[1][1]-arr[before][1]);
            if(res>len){
                res = len;
            }
            return;
        }

        for(int i=2;i<customer+2;i++){
            if(visited[i]==false){
                visited[i]=true;
                detect(k+1,customer,len+Math.abs(arr[i][0]-arr[before][0]) + Math.abs(arr[i][1]-arr[before][1]),i);
                visited[i]=false;
            }
        }
        return;
    }
}
