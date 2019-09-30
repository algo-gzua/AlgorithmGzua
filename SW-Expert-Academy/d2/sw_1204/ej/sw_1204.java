import java.io.*;
import java.util.Arrays;
 
public class Solution {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
 
    public static void main(String[] args) throws IOException {
        int testCase = 0, caseNum = 0;
        testCase = Integer.parseInt(bf.readLine());
        for(int i=0; i<testCase; i++){
            caseNum = Integer.parseInt(bf.readLine());
            choibinsoo(caseNum);
        }
        bw.close();
    }
 
    public static void choibinsoo(int num) throws IOException {
        String data;
        int max = 0, cbs = 0;
 
        Integer scoreArray[] = new Integer[101] ;
        Arrays.fill(scoreArray, 0);
 
        data = bf.readLine();
        String inputArray[] = data.split(" ");
 
        for(int i=0; i<1000; i++){
            int score = Integer.parseInt(inputArray[i]);
            scoreArray[score]+=1;
        }
 
        for(int j=0; j<scoreArray.length; j++){
            if(max <= scoreArray[j]){
                max = scoreArray[j];
                cbs = j;
            }
        }
        bw.write("#"+num+" "+cbs+"\n");
        bw.flush();
    }
}