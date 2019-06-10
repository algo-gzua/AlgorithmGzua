package sw_1256;

import java.io.*;
import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();

            int tc = Integer.parseInt(br.readLine());
            for(int i=1;i<=tc;i++){

                int index = Integer.parseInt(br.readLine());
                String str = br.readLine().toString();
                int length = str.length();
                String[] arr = new String[length];

                for(int j=0;j<length;j++){
                    arr[j]=str.substring(j);
                }
                Arrays.sort(arr);
                sb.append("#"+i+" "+arr[index-1]+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
