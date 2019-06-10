package boj_1110;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            int input = Integer.parseInt(br.readLine());

            int a = input / 10;
            int b = input % 10;
            int result = 0;
            int cnt=0;

            while(input != result || cnt == 0){
                int x = (a + b) % 10;

                result = (b * 10) + x;

                a = result / 10;
                b = result % 10;

                cnt++;
            }

            sb.append(cnt);
            bw.write(sb.toString());
            bw.flush();

        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
