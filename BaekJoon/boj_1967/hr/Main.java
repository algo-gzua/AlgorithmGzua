package boj_1967;

import java.io.*;
import java.util.*;

class Info{
    int parent;
    int dist;

    Info(int p, int d){
        this.parent = p;
        this.dist = d;
    }
}
public class Main {
    static int[] longest;
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int n = Integer.parseInt(br.readLine());

            ArrayList<Info>[] arr = new ArrayList[n+1];

            for (int l = 0; l <= n; l++) {
                arr[l] = new ArrayList<>();
            }
            Info info;

            for(int i=0;i<n-1;i++){
                st = new StringTokenizer(br.readLine());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                info = new Info(x,weight);
                arr[y].add(info);
                info = new Info(y,weight);
                arr[x].add(info);
            }
            bfs(1,n+1,arr);

            int res = 0;

            for(int j=1;j<n+1;j++){
                if(longest[res]<longest[j]){
                    res = j;
                }
            }

            bfs(res,n+1,arr);

            res = 0;
            for(int k=1;k<n+1;k++){
                if(longest[res]<longest[k]){
                    res = k;
                }
            }
            sb.append(longest[res]);
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static void bfs(int start, int n, ArrayList<Info>[] arr){ //n = n+1
        boolean[] visited = new boolean[n];
        longest = new int[n];
        Queue<Integer> q =new LinkedList<>();
        q.offer(start);
        int next = 0;
        while(!q.isEmpty()){
            int now = q.poll();
            visited[now] = true;
            for(int i=0;i<arr[now].size();i++){
                next = arr[now].get(i).parent;
                if(!visited[next]){
                    longest[next] = longest[now]+arr[now].get(i).dist;
                    q.offer(next);
                }
            }
        }
    }
}
