package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int a, b;
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
                for (int j = 0; j < 3; j++) System.out.print(reverseA[j]);
                break;
            } else {
                for (int j = 0; j < 3; j++) System.out.print(reverseB[j]);
                break;
            }
        }
    }
}
