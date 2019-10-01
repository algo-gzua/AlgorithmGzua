import java.io.*;
import java.util.Arrays;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int caseNum = Integer.parseInt(bf.readLine());
        int[] inputNumArray = new int[caseNum];

        for(int i=0; i<caseNum; i++){
            int inputNum = Integer.parseInt(bf.readLine());
            inputNumArray[i] = inputNum;
        }

        Arrays.sort(inputNumArray);
        for(int i=0; i<caseNum; i++){
            bw.write(inputNumArray[i]+"\n");
        }

        bw.flush();
        bw.close();
    }
}