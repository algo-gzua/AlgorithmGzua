package com.company;
import java.io.*;
import java.util.Stack;

public class Main {
    private static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static int maxVolume = 0;

    public static void main(String[] args) throws IOException {
        int lastVolume = 0;

        String inputNum = bf.readLine();
        String[] inputNumArray = inputNum.split(" ");

        int track = Integer.parseInt(inputNumArray[0]);
        int startVolume = Integer.parseInt(inputNumArray[1]);
        maxVolume = Integer.parseInt(inputNumArray[2]);

        String inputNum2 = bf.readLine();
        String[] changeVolumeList = inputNum2.split(" ");

        Stack<Integer> stack = new Stack<>();

        stack.push(startVolume);
        for(int i=0; i<track; i++){
            if(!stack.empty()) {
                stack = switchStack(stack, Integer.parseInt(changeVolumeList[i]));
            } else {
                break;
            }
        }
        int size = stack.size();

        if(stack.empty()){
            lastVolume = -1;
        } else {
            for(int i=0; i<size; i++){
                lastVolume = Math.max(stack.pop(), lastVolume);
            }
        }

        bw.write(lastVolume+"\n");
        bw.flush();
        bw.close();
    }

    public static Stack switchStack(Stack<Integer> stack, int changeVolume){
        Stack<Integer> newStack = new Stack<>();
        int size = stack.size();
        for(int i=0; i<size; i++){
            int currentVolume = stack.pop();
            int plus = currentVolume + changeVolume;
            int minus = currentVolume - changeVolume;
            if(plus >= 0 && plus <= maxVolume && !newStack.contains(plus)){
                newStack.push(plus);
            }
            if(minus >= 0 && minus <= maxVolume && !newStack.contains(minus)){
                newStack.push(minus);
            }
        }
        return newStack;
    }
}
