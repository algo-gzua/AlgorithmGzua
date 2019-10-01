import java.io.*;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int testCaseNum = 0;
        testCaseNum = Integer.parseInt(bf.readLine());
        for(int i=1; i<=testCaseNum; i++){
            OX();
        }
        bw.close();
    }

    public static void OX() throws IOException {
        int score = 0, sumScore = 0;
        String data = bf.readLine();
        char[] stringArray = data.toCharArray();

        for (char quizChar : stringArray) {
            if(quizChar=='O'){
                score+=1;
                sumScore+=score;
            } else {
                score=0;
            }
        }

        bw.write(sumScore+"\n");
        bw.flush();
    }
}