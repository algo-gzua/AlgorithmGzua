package BJ_2839;

import java.io.*;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            int input = Integer.parseInt(br.readLine());
            int N = input/5;
            int x=0;
            int y=0;
            int result=-1;

            for (int i=N; i>=0; i--){
                x = input - (5 * i);;
                if(x % 3 == 0){
                    result = i + (x/3);
                    break;
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
