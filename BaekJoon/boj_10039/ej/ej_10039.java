import java.io.*;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int average = 0;

        for(int i=0; i<5; i++){
            String inputNum = bf.readLine();
            int strToInt = Integer.parseInt(inputNum);
            if(strToInt<40) strToInt = 40;
            average+=strToInt;
        }

        average = average/5;
        bw.write(average+"\n");
        bw.flush();
        bw.close();
    }
}