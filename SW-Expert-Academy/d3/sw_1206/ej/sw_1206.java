package com.company;
import java.io.*;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int buildingNum = 0;
        for(int i=1; i<=10; i++){
            buildingNum = Integer.parseInt(bf.readLine());
            jomang(i, buildingNum);
        }
        bw.close();
    }

    public static void jomang(int caseNum, int buildingNum) throws IOException {
        String data;
        int max = 0, gapNum = 0, jomangValue = 0;

        data = bf.readLine();
        String inputArray[] = data.split(" ");

        for(int i=2; i<buildingNum-2; i++){
            int currentHeight = Integer.parseInt(inputArray[i]);
            for(int j=i-2; j<=i+2; j++){
                int compareHeight = Integer.parseInt(inputArray[j]);
                if(j!=i && max <= compareHeight){
                    max = compareHeight;
                }
            }

            if(max>=currentHeight) gapNum = 0;
            else gapNum = currentHeight-max;

            jomangValue += gapNum;
            max = 0;
        }

        bw.write("#"+caseNum+" "+jomangValue+"\n");
        bw.flush();
    }
}