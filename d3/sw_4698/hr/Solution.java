package date_190501.sw_4698;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int size = 2000001;
    static boolean[] arr = new boolean[size];

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            arrInit();
            int a,b;
            String d;
            int tc = Integer.parseInt(br.readLine());
            for(int i=1;i<=tc;i++){
                int cnt = 0;
                st = new StringTokenizer(br.readLine());
                d = st.nextToken();
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                for(int j=a;j<=b;j++){
                    if(arr[j]==false){
                        String str = String.valueOf(j);
                        if(str.contains(d)){
                            cnt++;
                        }
                    }
                }
                sb.append("#"+i+" "+cnt+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void arrInit(){
        arr[0] = arr[1] = true;
        for(int i=2;i<size;i++){
            for(int j=2;j<size/i;j++){
                arr[i*j]=true;
            }
        }
    }
}
