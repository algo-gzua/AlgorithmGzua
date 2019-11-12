package boj_4195_친구네트워크;

import java.io.*;
import java.util.*;

public class Main {
    static int F;
    static int[] root;
    static int[] friend_num;
    public static void main(String[] arg){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            int tc = Integer.parseInt(br.readLine());
            for(int i=0;i<tc;i++){
                HashMap<String, Integer> friend = new HashMap<>();
                F = Integer.parseInt(br.readLine());
                int num = 1;
                root = new int[F*3];
                friend_num = new int[F*3];

                for(int j=0;j<F*3;j++){
                    root[j] = j;
                    friend_num[j] = 1;
                }

                for(int j=0;j<F;j++){
                    String[] s = br.readLine().split(" ");
                    for(int k=0;k<2;k++){
                        if (!friend.containsKey(s[k])){
                            friend.put(s[k],num);
                            num++;
                        }
                    }
                    sb.append(union(friend.get(s[0]),friend.get(s[1]))+"\n");
                }
            }
            bw.write(sb.toString());
            bw.flush();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static int find(int x){
        if(root[x] == x){
            return x;
        }else{
            return find(root[x]);
        }
    }

    static int union(int x, int y){
        x = find(x);
        y = find(y);
        if(x!=y){
            root[y] = x;
            friend_num[x] += friend_num[y];
            friend_num[y] = 1;
        }
        return friend_num[x];
    }
}
