package boj_2573_빙산;

import java.io.*;
import java.util.*;

class Pair{
    int y,x;

    public Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}
public class Main {
    static int[][] dir = {{0,-1},{-1,0},{0,1},{1,0}};
    static int N,M,Year;
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            int[][] map = new int[N][M];

            for(int i=0;i<N;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<M;j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            while(check(map) == 0 || check(map) == 1 || check(map) == 2){
                if(check(map) == 2){
                    sb.append(Year);
                    break;
                }else if(check(map)==1){
                    sb.append("0");
                    break;
                }
                melting(map);

            }

            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }

    static void melting(int[][] map){
        Queue<Pair> q = new LinkedList<>();
        int[][] cnt = new int[N][M];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] != 0){
                    Pair p = new Pair(i,j);
                    q.add(p);
                }
                int c = 0;
                for(int k=0;k<4;k++){
                    int ny = i+dir[k][0];
                    int nx = j+dir[k][1];
                    if(ny>=0 && nx>=0 && ny<N && nx<M && map[i][j] != 0 && map[ny][nx] == 0){
                        c++;
                    }
                }
                cnt[i][j] = c;
            }
        }

        while(!q.isEmpty()){
            Pair p = q.poll();
            map[p.y][p.x] -= cnt[p.y][p.x];
            if(map[p.y][p.x] < 0){
                map[p.y][p.x] = 0;
            }
        }
        Year++;
    }

    static int check(int[][] map){
        boolean[][] visited = new boolean[N][M];
        boolean flag = false;
        Queue<Pair> q = new LinkedList<>();

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] != 0 && !visited[i][j] && !flag){
                    flag = true;
                    Pair p = new Pair(i,j);
                    q.add(p);
                    while(!q.isEmpty()){
                        p = q.poll();
                        visited[p.y][p.x] = true;
                        for(int k=0;k<4;k++){
                            int ny = p.y+dir[k][0];
                            int nx = p.x+dir[k][1];
                            if(ny>=0 && nx>=0 && ny<N && nx<M && map[ny][nx] != 0 && !visited[ny][nx]){
                                visited[ny][nx] = true;
                                Pair p2 = new Pair(ny,nx);
                                q.add(p2);
                            }
                        }
                    }
                }
                //섬이 두개일때
                if(map[i][j] != 0 && !visited[i][j] && flag){
                    return 2;
                }
                //섬이 모두 가라앉았을때
                if(i==N-1 && j==M-1 && !flag){
                    return 1;
                }
            }
        }
        //섬이 아직 한덩어리일때
        return 0;
    }
}