package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int a, b, maxNum=0;
        int[] reverseA = new int[3];
        int[] reverseB = new int[3];
        a = sc.nextInt();
        b = sc.nextInt();

        for(int i=0; i<3; i++){
            if(i<2) {
                reverseA[i] = a % 10;
                reverseB[i] = b % 10;
            } else {
                reverseA[i] = a;
                reverseB[i] = b;
            }
            a = a / 10;
            b = b / 10;
        }

        for(int i=0; i<3; i++) {
            if (reverseA[i] == reverseB[i]) continue;
            if (reverseA[i] > reverseB[i]) {
                maxNum = 1;
                break;
            } else {
                maxNum = 2;
                break;
            }
        }

        if(maxNum==1){
            for(int i=0; i<3; i++) System.out.print(reverseA[i]);
        } else {
            for(int i=0; i<3; i++) System.out.print(reverseB[i]);
        }
    }
}
