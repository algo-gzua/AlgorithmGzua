package boj_11438_LCA2;

import java.io.*;
import java.util.*;

class Info{
    int num;
    int d;

    public Info(int num, int d){
        this.num = num;
        this.d = d;
    }
}

public class Main {
    static ArrayList<Integer>[] node;
    static int N;
    static int[][] parent;
    static int LENGTH = 20;
    static int[] depth;

    static void dfs(){
        boolean[] visited = new boolean[N+1];
        Queue<Info> q = new LinkedList<>();

        Info info = new Info(1,1);
        visited[1] = true;
        q.add(info);

        while(!q.isEmpty()){
            info = q.poll();
            depth[info.num] = info.d;

            for(int i=0;i<node[info.num].size();i++){
                int x = node[info.num].get(i);

                if(!visited[x]){
                    parent[x][0] = info.num;
                    visited[x] = true;
                    Info i2 = new Info(x,info.d+1);
                    q.add(i2);
                }
            }
        }

    }

    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            N = Integer.parseInt(br.readLine());
            node = new ArrayList[N+1];
            parent = new int[N+1][LENGTH];
            depth = new int[N+1];
            int a,b;

            for(int i=1;i<=N;i++){
                node[i] = new ArrayList<>();
            }

            for(int[] row:parent){
                Arrays.fill(row,-1);
            }

            for(int i=0;i<N-1;i++){
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                node[a].add(b);
                node[b].add(a);
            }

            dfs();

            for(int dep=0;dep<LENGTH-1;dep++){
                for(int n=1;n<=N;n++){
                    if(parent[n][dep] != -1){
                        parent[n][dep+1] = parent[parent[n][dep]][dep];
                    }
                }
            }

            int M = Integer.parseInt(br.readLine());
            for(int i=0;i<M;i++){
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());

                if(depth[a] < depth[b]){
                    int temp = a;
                    a = b;
                    b = temp;
                }

                int diff = depth[a]-depth[b];

                int binary = 0;
                while(diff>0){
                    if(diff%2==1){
                        a = parent[a][binary];
                    }
                    diff/=2;
                    binary++;
                }

                if(a!=b){
                    for(int k = LENGTH-1;k>=0;k--){
                        if(parent[a][k] != -1 && parent[a][k] != parent[b][k]){
                            a = parent[a][k];
                            b = parent[b][k];
                        }
                    }
                    a = parent[a][0];
                }
                sb.append(a+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e) {
            e.printStackTrace();
        }
    }
}
