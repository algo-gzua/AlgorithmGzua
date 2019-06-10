package sw_2819;

import java.io.*;
import java.util.*;

public class Solution {
    static int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}}; //좌 상 우 하
    static int[][] map = new int[4][4];
    static Set<Integer> set = new HashSet<>();
    static StringBuilder sb2 = new StringBuilder();

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int tc = Integer.parseInt(br.readLine());

            for(int i=1;i<=tc;i++){
                sb.append("#").append(i).append(" ");
                for(int j=0;j<4;j++){
                    st = new StringTokenizer(br.readLine());
                    for(int k=0;k<4;k++){
                        map[j][k] = Integer.parseInt(st.nextToken());
                    }
                }
                for (int l=0;l<4;l++){
                    for (int m=0;m<4;m++){
                        dfs(l,m,0);
                        sb2.setLength(0);
                    }
                }
                sb.append(set.size()+"\n");
                set.clear();
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void dfs(int x, int y, int cnt){
        if(cnt == 7){
            set.add(Integer.parseInt(sb2.toString()));
            return;
        }

        for(int i=0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && nx <4 && ny >= 0 && ny < 4){
                sb2.append(map[x][y]);
                dfs(nx,ny,cnt+1);
                sb2.deleteCharAt(cnt);
            }
        }
    }
}
