package boj_2910;

import java.io.*;
import java.util.*;

class Info{
    int num;
    int freq;
    int seq;

    public Info(int num,int freq, int seq){
        this.num = num;
        this.freq = freq;
        this.seq = seq;
    }
}

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            HashMap<Integer,Integer> mp = new HashMap<>();

            Info[] info = new Info[N];

            for(int k=0;k<N;k++){
                info[k] = new Info(0,0,0);
            }

            st = new StringTokenizer(br.readLine());
            int cnt = 0;

            for(int i=0;i<N;i++){
                int num = Integer.parseInt(st.nextToken());
                if(!mp.containsKey(num)){
                    mp.put(num,cnt);
                    info[cnt] = new Info(num,1,cnt);
                    cnt++;
                }else{
                    info[mp.get(num)].num = num;
                    info[mp.get(num)].freq++;
                    continue;
                }
            }

            Arrays.sort(info, new Comparator<Info>(){
                @Override
                public int compare(Info i1, Info i2){
                    int i1Freq = i1.freq;
                    int i2Freq = i2.freq;
                    if(i1Freq == i2Freq){
                        return Integer.compare(i1.seq, i2.seq);
                    }
                    return Integer.compare(i2.freq,i1.freq);
                }
            });

            for(int k=0;k<N;k++){
                for(int l=0;l<info[k].freq;l++){
                    sb.append(info[k].num + " ");
                    if(info[k].freq == 0){
                        break;
                    }
                }
            }
            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}