import java.io.*;
import java.util.*;

class Pair{
    int col;
    int row;
    int cnt;
    Pair(int col, int row,int cnt){
        this.col = col;
        this.row = row;
        this.cnt = cnt;
    }
}

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[][] dir = {{0,-1},{-1,0},{0,1},{1,0}};

            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            int[][] tomato = new int[col][row];

            //??
            Queue<Pair> que = new LinkedList<Pair>();

            for(int i=0;i<col;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<row;j++){
                    tomato[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for(int k=0;k<col;k++){
                for(int l=0;l<row;l++){
                    if(tomato[k][l]==1){
                        Pair p = new Pair(k,l,0);
                        que.add(p);
                    }
                }
            }
            int result = 0;
            while(!que.isEmpty()){
                Pair p = que.poll();
                for(int m=0;m<4;m++){
                    int n_c = p.col+dir[m][0];
                    int n_r = p.row+dir[m][1];
                    if(n_c >= 0 && n_c < col && n_r >= 0 && n_r < row && tomato[n_c][n_r] == 0){
                        tomato[n_c][n_r] = 1;
                        Pair p2 = new Pair(n_c,n_r,p.cnt+1);
                        que.add(p2);
                    }
                }
                result = p.cnt;
            }

            for(int a=0;a<col;a++){
                for(int b=0;b<row;b++){
                    if(tomato[a][b]==0){
                        result = -1;
                    }
                }
            }
            sb.append(result);
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
