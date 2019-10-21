package boj_4673_셀프넘버;

import java.io.*;

public class Main {
    static boolean[] self;
    public static void main(String[] arg){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
            StringBuilder sb = new StringBuilder();
            self = new boolean[10010];

            for(int i=1;i<10001;i++){
                self_number(i);
            }

            for(int i=1;i<10001;i++){
                if(!self[i]){
                    sb.append(i + "\n");
                }
            }

            bw.write(sb.toString());
            bw.flush();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    static void self_number(int num){
        int res = num;

        while(num != 0){
            res += num%10;
            num /= 10;
        }

        if(res > 10001) return;

        self[res] = true;
    }
}
