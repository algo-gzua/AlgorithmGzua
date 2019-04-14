package solution;

import java.io.*;

public class Solution {
	static int size = 100;
	static int[][] map;
	static boolean[][] visited;
	static int[][] dir= {{-1,0},{1,0},{0,-1},{0,1}}; //»óÇÏÁÂ¿ì
	static boolean out;
	public static void main(String[] arg) {
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))){
			
			
			StringBuilder sb = new StringBuilder();
			
			for(int i=0;i<1;i++) {
				
				int caseNum = Integer.parseInt(br.readLine());
				map = new int[size][size];
				visited = new boolean[size][size];
				
				for (int j=0;j<size;j++) {
					String row = br.readLine();
					
					for(int k=0;k<size;k++) {
						map[j][k] = Integer.parseInt(row.charAt(k)+"");
					}
				}
				
				out = false;
				
				dfs(1,1);
				
				if(out) { sb.append("#" + caseNum + " 1\n"); }
				else { sb.append("#" + caseNum + " 0\n"); }
			}
			
			bw.write(sb.toString());
			bw.flush();
			
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	static void dfs(int y, int x) {
		int ny, nx;
		
		if(map[y][x]==3) {
			out = true;
			return;
		}
		
		for(int i=0;i<4;i++) {
			ny = y+dir[i][0];
			nx = x+dir[i][1];
			if(ny>=0 && nx>=0 && ny<size && nx<size && map[ny][nx] != 1 && !visited[ny][nx]) {
				visited[y][x] = true;
				dfs(ny,nx);
			}
		}
	}
}
