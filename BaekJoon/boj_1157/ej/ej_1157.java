package com.company;
import java.io.*;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int compareValue = 0, maxValue = 0;

        String inputStr = bf.readLine();
        int[] asciiArray = new int[26];
        for(int i=0; i<inputStr.length(); i++){
            int charToAscii = (int) inputStr.charAt(i);
            //대문자65-90 소문자97-122
            if(charToAscii>=97 && charToAscii<=122){
                charToAscii-=32;
            }
            charToAscii-=65;
            asciiArray[charToAscii] += 1;
        }

        for (int j=0; j<asciiArray.length; j++){
            if(compareValue < asciiArray[j]) {
                compareValue = asciiArray[j];
                maxValue = j+65;
            } else if(compareValue == asciiArray[j]){
                maxValue = 63;
            }
        }

        bw.write((char)maxValue +"\n");
        bw.flush();
        bw.close();
    }
}