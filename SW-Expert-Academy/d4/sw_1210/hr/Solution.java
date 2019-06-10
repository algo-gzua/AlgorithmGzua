package date_190508.sw_1210;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int size = 100;
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            StringTokenizer st;
            int[][] board = new int[size][size];
            int num=0;
            for (int i = 1; i <= 10; i++) {
                int tc = Integer.parseInt(br.readLine());

                //배열초기화
                for (int j = 0; j < size; j++) {
                    String[] str = br.readLine().split(" ");
                    for (int k = 0; k < size; k++) {
                        board[j][k] = Integer.parseInt(str[k]);
                    }
                }
                //도착지점 찾기
                for(int l=0;l<size;l++){
                    if(board[size-1][l] == 2){
                        num = l;
                    }
                }

                int res = detect(board,size-2,num);
                sb.append("#"+tc+" "+res+"\n");
            }
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static int detect(int[][] board, int y, int num){
        while(y!=0){
            //왼쪽탐색 -> 1이면 현재위치를 0으로바꾸고 왼쪽으로 한칸 이동
            if(num>0 && board[y][num-1]==1) {
                board[y][num]=0;
                num--;
            }
            //오른쪽탐색
            else if(num+1<size && board[y][num+1]==1){
                board[y][num]=0;
                num++;
            }
            //위쪽탐색
            else if(board[y-1][num]==1){
                y--;
            }
        }
        return num;
    }
}
