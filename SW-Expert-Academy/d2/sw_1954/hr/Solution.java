package solution;

import java.util.Scanner;

public class Solution {
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		int tc = s.nextInt();
		for (int i =1;i<=tc;i++) {
			
			int num = s.nextInt();
			int[][] arr = new int[num][num];
			if(num%2==0) {
				snail_even(arr,num,1,0,num);
			}
			else {
				snail_odd(arr,num,1,0,num);
			}
			System.out.println("#"+i);
			for(int j=0;j<num;j++) {
				for(int k=0;k<num;k++) {
					System.out.print(arr[j][k]+" ");
				}
				System.out.println();
			}
		}
	}
	public static int[][] snail_odd(int[][] arr, int num, int insertNum,int x,int y) {
		if(num==1) {
			arr[x][x]=insertNum;
			return arr;
		}
		else {
			for(int i=0;i<num-1;i++) {
				arr[x][i+x]=insertNum;
				insertNum++;
			}
			for(int j=0;j<num-1;j++) {
				arr[j+x][y-1]=insertNum;
				insertNum++;
			}
			for(int k=num-1;k>0;k--) {
				arr[y-1][k+x]=insertNum;
				insertNum++;
			}
			for(int l=num-1;l>0;l--) {
				arr[l+x][x]=insertNum;
				insertNum++;
			}
		}
		return snail_odd(arr,num-2,insertNum,x+1,y-1);
	}
	public static int[][] snail_even(int[][] arr, int num, int insertNum,int x,int y) {
		if(num==0) {
			return arr;
		}
		else {
			for(int i=0;i<num-1;i++) {
				arr[x][i+x]=insertNum;
				insertNum++;
			}
			for(int j=0;j<num-1;j++) {
				arr[j+x][y-1]=insertNum;
				insertNum++;
			}
			for(int k=num-1;k>0;k--) {
				arr[y-1][k+x]=insertNum;
				insertNum++;
			}
			for(int l=num-1;l>0;l--) {
				arr[l+x][x]=insertNum;
				insertNum++;
			}
		}
		return snail_even(arr,num-2,insertNum,x+1,y-1);
	}
}
