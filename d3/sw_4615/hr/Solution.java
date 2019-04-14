package solution;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
	static int[] dy = {-1,-1,-1,0,1,1,1,0};
	static int[] dx = {-1,0,1,1,1,0,-1,-1};
	
	public static void main(String[] arg) {
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
			
			StringBuilder sb = new StringBuilder();
			StringTokenizer st;
			int tc=Integer.parseInt(br.readLine());
			int N,cnt,x,y,player;
			
			
			for(int i=1;i<=tc;i++) {
				st = new StringTokenizer(br.readLine());
				
				N = Integer.parseInt(st.nextToken()); //보드의 한 변의 길이
				cnt = Integer.parseInt(st.nextToken()); //돌을 놓는 횟수
				int[][] board = new int[N][N];
				int res1 = 0; int res2 = 0;
				
				defaultSet(N,board); 

				for(int j=0;j<cnt;j++) {
					st = new StringTokenizer(br.readLine());
					y = Integer.parseInt(st.nextToken());
					x = Integer.parseInt(st.nextToken());
					player = Integer.parseInt(st.nextToken());
					turn(y-1,x-1,player,board);
				}
				for(int k=0;k<N;k++) {
					for(int l=0;l<N;l++) {
						if(board[k][l]==1) {
							res1++;
						}
						if(board[k][l]==2) {
							res2++;
						}
					}
				}
				sb.append("#"+i+" "+res1).append(" "+res2+"\n");
			}
			
			bw.write(sb.toString());
			bw.flush();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	public static void turn(int y, int x, int player,int[][] arr) {
		arr[y][x] = player;
		
		for (int i=0;i<8;i++) {
			int ny = y + dy[i];
            int nx = x + dx[i];
            while(ny>=0 && nx>=0&& ny<arr.length && nx<arr.length) {
            	if(arr[ny][nx]==player) {
            		int Y = y + dy[i];
            		int X = x + dx[i];
            		while(arr[Y][X] != player) {
            			arr[Y][X] = player;
            			Y += dy[i];
                		X += dx[i];
            		}
            		break;
            	}
            	if(arr[ny][nx]==0) {
            		break;
            	}
            	ny += dy[i];
            	nx += dx[i];
            }
		}
	}
	
	public static void defaultSet(int n, int[][] arr) {
		int num = 0;
		
		switch(n) {
		case 4:
			num = 1;
			break;
		case 6:
			num = 2;
			break;
		case 8:
			num = 3;
			break;
		default:
			break;
		}		
		arr[num][num] = 2;
		arr[num][num+1] = 1;
		arr[num+1][num] = 1;
		arr[num+1][num+1] = 2;
	}
	
}