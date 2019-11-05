package boj_11437_LCA;

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
    static int[] depth;
    static int[][] parent;
    static final int LENGTH = 20;
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int N = Integer.parseInt(br.readLine());
            parent = new int[LENGTH][N+1];
            depth = new int[N+1];

            node = new ArrayList[N+1];
            for(int i=1;i<=N;i++){
                node[i] = new ArrayList<>();
            }

            for(int i=0;i<N-1;i++){ //인접리스트 초기화
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                node[a].add(b);
                node[b].add(a);
            }

            for(int[] row:parent){ //parent
                Arrays.fill(row,-1);
            }

            dfs(N);

            for(int dep=0; dep<20; dep++){
                for(int n=1; n<=N; n++){
                    if(parent[dep][n] != -1){
                        parent[dep+1][n] = parent[dep][parent[dep][n]];
                    }
                }
            }

            int M = Integer.parseInt(br.readLine());
            for(int i=0;i<M;i++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                if(depth[x]<depth[y]){
                    int temp = x;
                    x = y;
                    y = temp;
                }

                int diff = depth[x]-depth[y];

                int binary = 0;
                while(diff>0){
                    if(diff%2 == 1){
                        x = parent[binary][x];
                    }
                    diff /= 2;
                    binary++;
                }

                if(x!=y){
                    for(int k=LENGTH-1 ; k>=0;k--){
                        if(parent[k][x] != -1 && parent[k][x] != parent[k][y]){
                            x = parent[k][x];
                            y = parent[k][y];
                        }
                    }
                    x = parent[0][x];
                }
                sb.append(x+"\n");
            }

            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static void dfs(int N){
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

                if(!visited[x]) {
                    Info i2 = new Info(x, info.d + 1);
                    parent[0][x] = info.num;
                    visited[x] = true;
                    q.add(i2);
                }
            }
        }
    }
}
