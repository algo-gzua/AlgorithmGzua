package sw_1258;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class Pair{
    int row;
    int col;
    int mul;

    Pair(int row, int col)
    {
        this.row = row;
        this.col = col;

        mul = row * col;
    }
}

public class Solution {
    static int[][] matrix;
    static boolean[][] visited;
    static int N;
    static ArrayList<Pair> pair;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;

            int tc = Integer.parseInt(br.readLine());

            for(int i=1;i<=tc;i++){
                N = Integer.parseInt(br.readLine());
                matrix = new int[N+1][N+1];

                for(int j=0;j<N;j++){
                    st = new StringTokenizer(br.readLine());
                    for(int k=0;k<N;k++){
                        matrix[j][k] = Integer.parseInt(st.nextToken());
                    }
                }
                detect();
                sb.append("#"+i+" "+pair.size()+ " ");
                for(int l=0;l<pair.size();l++){
                    sb.append(pair.get(l).col + " " + pair.get(l).row + " ");
                }
                sb.append("\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    static void detect(){
        int y,x;
        int row,col;

        pair = new ArrayList<>();
        visited = new boolean[N+1][N+1];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j] != 0 && !visited[i][j]){
                    y = i;
                    x = j;
                    row = 0; col = 0;

                    while(matrix[y][x] != 0){
                        visited[y][x] = true;
                        row++;
                        x++;
                    }

                    y=i;
                    x=j;
                    while(matrix[y][x] != 0){
                        visited[y][x] = true;
                        col++;
                        y++;
                    }

                    Pair p = new Pair(row, col);
                    pair.add(p);

                    for(int l=i;l<i+col;l++){
                        for(int m=j;m<j+row;m++){
                            visited[l][m] = true;
                        }
                    }
                }
            }
        }

        Collections.sort(pair, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.mul < o2.mul){
                    return -1;
                }else if(o1.mul == o2.mul){
                    if(o1.row < o2.row){
                        return 1;
                    }else { return -1; }
                }
                return 1;
            }
        });
    }
}
