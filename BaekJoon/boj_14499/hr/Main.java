package boj_14499;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[] dice = new int[6];
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int[] dy = {0, 1, -1, 0, 0};
            int[] dx = {0, 0, 0, -1, 1};

            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int[][] map = new int[N][M];

            for(int i=0;i<N;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<M;j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            st = new StringTokenizer(br.readLine());

            for(int k=0;k<K;k++){
                int req = Integer.parseInt(st.nextToken());
                int nx = x+dx[req];
                int ny = y+dy[req];

                if(nx >= N || nx < 0 || ny >= M || ny < 0) {
                    continue;
                }


                if(map[nx][ny] == 0){
                    Relocate(req);
                    map[nx][ny] = dice[0];
                    sb.append(dice[3]+"\n");

                }else{
                    Relocate(req);
                    dice[0] = map[nx][ny];
                    map[nx][ny] = 0;
                    sb.append(dice[3]+"\n");
                }
                x = nx; y = ny;
            }
            bw.write(sb.toString());
            bw.flush();


        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static void Relocate(int req){
        switch(req){
            case 1: //동
                swap(0,5);
                swap(0,3);
                swap(0,4);
                break;
            case 2: //서
                swap(0,4);
                swap(0,5);
                swap(3,5);
                break;
            case 3: //북
                swap(0,1);
                swap(0,2);
                swap(2,3);
                break;
            case 4: //남
                swap(0,2);
                swap(1,0);
                swap(1,3);
                break;
        }
    }
    public static void swap(int a, int b) {
        int tmp = dice[a];
        dice[a] = dice[b];
        dice[b] = tmp;
    }
}
