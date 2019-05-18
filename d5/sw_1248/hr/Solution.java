package sw_1248;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
    static int[] depth;
    static int[] parents;
    static int treeNum=0;
    static ArrayList<Integer>[] tree;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int tc = Integer.parseInt(br.readLine());
            StringTokenizer st;

            for(int i=1;i<=tc;i++){
                st = new StringTokenizer(br.readLine());
                int V = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                tree = new ArrayList[V+1];
                parents = new int[V+1];
                treeNum = 0;


                for(int k=1;k<=V;k++){
                    tree[k] = new ArrayList<>();
                }

                int x,y;
                st = new StringTokenizer(br.readLine());
                for(int j=1;j<=E;j++){
                    x = Integer.parseInt(st.nextToken());
                    y = Integer.parseInt(st.nextToken());
                    tree[x].add(y);
                    parents[y] = x;
                }
                depth = new int[V+1];
                check_depth(1,1);
                int res = LCA(a,b);
                tree_num(res);
                int res2 = treeNum+1;

                sb.append("#"+i+" "+res+" "+res2+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    //깊이를 저장하는 배열(a=1, index=1)
    static void check_depth(int a, int index){
        if(!tree[index].isEmpty()){
            for(int i=0;i<tree[index].size();i++){
                depth[tree[index].get(i)] = a;
                check_depth(a+1,tree[index].get(i));
            }
        }
    }
    static int LCA(int a, int b){
        //깊이가 다르면
        if(depth[a] != depth[b]){
            //깊이를 맞춰준다
            while(depth[a] != depth[b]){
                if(depth[a]<depth[b]){
                    b = parents[b];
                }else{
                    a = parents[a];
                }
            }
        }
        //깊이가 같으면
        if(parents[a] != parents[b]){
            while(parents[a] != parents[b]){
                a = parents[a];
                b = parents[b];
            }
        }
        return parents[a];
    }
    //서브트리의 개수
    static void tree_num(int a){
        if(!tree[a].isEmpty()){
            for(int i=0;i<tree[a].size();i++) {
                tree_num(tree[a].get(i));
                treeNum++;
            }
        }
    }
}
