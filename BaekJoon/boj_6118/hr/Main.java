package boj_6118;

import java.io.*;
import java.util.*;

class Info{
    int num;
    int cnt;
    Info(int num, int cnt){
        this.num = num;
        this.cnt = cnt;
    }
}
public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken())+1;
            int M = Integer.parseInt(st.nextToken());

            ArrayList<Integer>[] board = new ArrayList[N];
            for(int i=0;i<N;i++){
                board[i] = new ArrayList<>();
            }

            for(int j=0;j<M;j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                board[a].add(b);
                board[b].add(a);
            }

            Queue<Info> q = new LinkedList<>();
            int[] distance = new int[N];
            Info info = new Info(1,0);
            q.add(info);

            while(!q.isEmpty()){
                info = q.poll();
                for(int i=0;i<board[info.num].size();i++){
                    int x = board[info.num].get(i);
                    if(distance[x] == 0 && x != 1){
                        Info i2 = new Info(x,info.cnt + 1);
                        distance[x] = info.cnt + 1;
                        q.add(i2);
                    }
                }
            }
            int max = 0;
            int cnt=0;
            int res = 0;
            for(int i=1;i<N;i++){
                if(distance[i] > max){
                    max = distance[i];
                    res = i;
                    cnt = 0;
                }
                if(distance[i] == max){
                    cnt++;
                }
            }
            sb.append(res + " " + distance[res] + " " + cnt);
            bw.write(sb.toString());
            bw.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
