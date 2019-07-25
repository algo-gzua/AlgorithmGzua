package boj_2589;

import java.io.*;
import java.util.*;

class Pair{
    int y2;
    int x2;

    public Pair(int y, int x){
        this.y2 = y;
        this.x2 = x;
    }
}

public class Main {
    static int y,x;
    static int[][] dir = {{0,-1},{-1,0},{0,1},{1,0}}; //좌 상 우 하
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());  //5
            x = Integer.parseInt(st.nextToken());  //7
            int[][] map = new int[y+1][x+1];
            for(int i=1;i<=y;i++){
                String str = br.readLine();
                for(int j=1;j<=x;j++){
                    if(str.charAt(j-1) == 'W'){
                        map[i][j] = 2; //바다 = 2
                    }else{
                        map[i][j] = 1; //육지 = 1
                    }
                }
            }
            int res = 0;
            int res2 = 0;
            for(int k=1;k<=y;k++){
                for(int l=1;l<=x;l++){
                    if(map[k][l] == 1){
                        res = bfs(map,k,l);
                        res2 = Math.max(res,res2);
                    }
                }
            }
            sb.append(res2);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static int bfs(int[][] map, int a, int b){ // map=map a=k b=l
        Pair p = new Pair(a,b);
        int[][] map2 = new int[y+1][x+1];
        Queue<Pair> q = new LinkedList<>();
        q.offer(p);

        while(!q.isEmpty()){
            p = q.poll();
            for(int i=0;i<4;i++){
                int n_y = p.y2 + dir[i][0];
                int n_x = p.x2 + dir[i][1];
                if(n_y <= y && n_x <= x && map[n_y][n_x] == 1 && map2[n_y][n_x] == 0){
                    map2[n_y][n_x] = map2[p.y2][p.x2]+1;
                    Pair p2 = new Pair(n_y,n_x);
                    q.offer(p2);
                }
            }
        }
        return map2[p.y2][p.x2];
    }
}
