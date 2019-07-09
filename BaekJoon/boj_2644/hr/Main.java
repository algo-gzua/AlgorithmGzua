package boj_2644;

import java.io.*;
import java.util.*;


public class Main {
    static boolean[] visited;
    static int n;
    static int[] cnt;
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;

            int N = Integer.parseInt(br.readLine());
            n = N+1;
            int[] arr = new int[n];
            cnt = new int[n];
            visited = new boolean[n];
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int M = Integer.parseInt(br.readLine());

            for(int i=0;i<M;i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                arr[b] = a;
            }
            int res = bfs(arr,x,y);
            if(x != y && res == 0){
                res = -1;
            }
            sb.append(res);

            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static int bfs(int[] arr, int x, int y){
        Queue<Integer> q = new LinkedList<>();
        q.offer(x);
        visited[x] = true;
        while(!q.isEmpty()){
            int now = q.poll();
            if(!visited[arr[now]] && arr[now] != 0){
                q.offer(arr[now]);
                visited[arr[now]] = true;
                cnt[arr[now]] = cnt[now]+1;
            }
            for(int i=1;i<n;i++){
                if(!visited[i] && arr[i]==now) {
                    q.offer(i);
                    visited[i] = true;
                    cnt[i] = cnt[now]+1;
                }
            }
        }
        return cnt[y];
    }
}
