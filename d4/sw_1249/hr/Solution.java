package date_190424.sw_1249;

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;



public class Solution {
    static int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}}; //좌 상 우 하
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();

            int tc = Integer.parseInt(br.readLine());
            for(int i=1;i<=tc;i++) {
                int N = Integer.parseInt(br.readLine());

                int[][] map = new int[N][N];

                for(int j=0;j<N;j++){
                    String str = br.readLine();
                    for(int k=0;k<N;k++){
                        map[j][k]=str.charAt(k)-'0';
                    }
                }
                int res = bfs(map,N);
                sb.append("#"+i+" "+res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(IOException e) {
            e.printStackTrace();
        }
    }

    static class Pair{
        int y,x;

        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    public static int bfs(int[][] map,int N){
        int[][] bfsMap = new int[N][N];
        boolean[][] visited = new boolean[N][N];
        visited[0][0]= true;

        for(int k=0;k<N;k++){
            for (int j=0;j<N;j++){
                bfsMap[k][j] = map[k][j];
            }
        }

        Queue<Pair> q = new LinkedList<>();

        //시작점 좌표를 큐에 push
        q.add(new Pair(0,0));
        bfsMap[0][0] = map[0][0];

        while(!q.isEmpty()){
            Pair p = q.poll();

            for(int i=0;i<4;i++){
                int y = p.y+dir[i][0];
                int x = p.x+dir[i][1];

                if (y < 0 || x < 0 || y >= N || x >= N) {
                    continue;
                }

                if((!visited[y][x] || bfsMap[y][x]>map[y][x]+bfsMap[p.y][p.x]) && y>=0 && x>=0 && y<N && x<N){
                        bfsMap[y][x] = map[y][x]+bfsMap[p.y][p.x];
                        q.add(new Pair(y,x));
                        visited[y][x]=true;
                }
            }
        }
        return bfsMap[N-1][N-1];
    }
}


