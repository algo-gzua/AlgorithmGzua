package boj_15559_내선물을받아줘;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};
    static int[][] count;
    public static void main(String[] arg){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            int res = 0;
            char[][] map = new char[N][M];
            count = new int[N][M];

            for(int i=0;i<N;i++){
                String s = br.readLine();
                for(int j=0;j<M;j++){
                    map[i][j] = s.charAt(j);
                }
            }

            res = present(map);

            sb.append(res);
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    static int present(char[][] map){
        boolean[][] visited = new boolean[N][M];
        int[][] intmap = new int[N][M];
        int cycle = 0;
        int cnt = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j]) {
                    int y = i;
                    int x = j;
                    while (!visited[y][x]) {
                        intmap[y][x] = cnt;
                        visited[y][x] = true;
                        switch (map[y][x]) {
                            case 'N':
                                y += dir[0][0];
                                break;
                            case 'E':
                                x += dir[1][1];
                                break;
                            case 'S':
                                y += dir[2][0];
                                break;
                            case 'W':
                                x += dir[3][1];
                                break;
                        }
                    }
                    if (intmap[y][x] == intmap[i][j]) {
                        cycle++;
                        cnt++;
                    } else {
                        cnt++;
                    }
                }else{
                    continue;
                }
            }
        }
        return cycle;
    }
}
