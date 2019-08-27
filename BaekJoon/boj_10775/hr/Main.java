package boj_10775;

import java.io.*;

public class Main {

    public static int[] parent = new int[100001];

    public static int find(int x){
        if(x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y){
        x = find(x);
        y = find(y);
        parent[x] = y;
    }


    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int G = Integer.parseInt(br.readLine());
            int P = Integer.parseInt(br.readLine());
            int res = 0;

            for(int j=1;j<=G;j++){
                parent[j] = j;
            }

            for(int i=1;i<=P;i++){
                int g = Integer.parseInt(br.readLine());
                int c = find(g);

                if(c == 0) break;

                union(c,c-1);
                res++;

            }
            sb.append(res);
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
