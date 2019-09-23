package boj_11559;

import java.io.*;
import java.util.*;

class Pair{
    int y;
    int x;
    char s;
    Pair(int y, int x, char s){
        this.y = y;
        this.x = x;
        this.s = s;
    }
}
public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();



            int[][] dir = {{0,-1},{-1,0},{1,0},{0,1}};
            char[][] board = new char[12][6];
            boolean[][] visited = new boolean[12][6];
            Queue<Pair> q = new LinkedList<Pair>();
            Queue<Pair> q2 = new LinkedList<Pair>();
            String str = "";

            for(int i=0;i<12;i++){
                str = br.readLine();
                for(int j=0;j<6;j++){
                    board[i][j] = str.charAt(j);
                }
            }

            boolean c = true;
            int res = 0;

            while(c) {
                c = false;
                for (int k = 0; k < 12; k++) {
                    for (int l = 0; l < 6; l++) {
                        if (board[k][l] != '.' && !visited[k][l]) {
                            Pair pair = new Pair(k, l, board[k][l]);
                            visited[k][l] = true;
                            q.offer(pair);
                            q2.offer(pair);
                        }
                        int cnt = 0;
                        while (!q.isEmpty()) {
                            cnt++;
                            Pair p = q.poll();
                            for (int m = 0; m < 4; m++) {
                                int ny = p.y + dir[m][0];
                                int nx = p.x + dir[m][1];
                                if (ny >= 0 && nx >= 0 && ny < 12 && nx < 6 && p.s == board[ny][nx] && !visited[ny][nx]) {
                                    Pair pair2 = new Pair(ny, nx, board[ny][nx]);
                                    visited[ny][nx] = true;
                                    q.offer(pair2);
                                    q2.offer(pair2);
                                }
                            }
                        }
                        if(cnt>=4){
                            c=true;
                            while(!q2.isEmpty()){
                                Pair pair = q2.poll();
                                board[pair.y][pair.x] = '.';
                            }
                        }else{
                            q2 = new LinkedList<Pair>();
                        }
                    }
                }
                if(c) {
                    res++;
                    for (int i = 0; i < 6; i++) {
                        int cnt = 0;
                        for (int j = 11; j >= 0; j--) {
                            visited[j][i] = false;
                            if (board[j][i] == '.') {
                                cnt++;
                            } else if (board[j][i] != '.' && cnt != 0) {
                                board[j + cnt][i] = board[j][i];
                                board[j][i] = '.';
                            } else {
                                continue;
                            }
                        }
                    }
                }

            }

            sb.append(res);
            bw.write(sb.toString());
            bw.flush();


        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
