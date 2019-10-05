package com.company;
import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int sum = 0, num1 = 0, num2 = 1;
        int inputNum = Integer.parseInt(bf.readLine());
        sum = num1 + num2;
        for(int i=inputNum; i>2; i--){
            num1 = num2;
            num2 = sum;
            sum = num1 + num2;
        }
        bw.write(sum+"\n");
        bw.flush();
        bw.close();
    }
}