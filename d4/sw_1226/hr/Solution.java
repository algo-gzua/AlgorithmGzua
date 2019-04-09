package solution;
import java.util.Scanner;

public class Solution {
	static int map_size=16;
	static int[][] map;
	static boolean[][] visited;
	static int[][] dir = {{-1,0},{1,0},{0,-1},{0,1}};
	static boolean out;
	public static void main(String[] arg) {
		Scanner s = new Scanner(System.in);
		String row = null;
		//int tc = s.nextInt();
		for(int i=1;i<11;i++) {
			map = new int[map_size][map_size];
			visited = new boolean[map_size][map_size];
			//맵 입력
			for(int j=0;j<16;j++) {
				row = s.next();
				for(int k=0;k<16;k++) {
					map[j][k]=Integer.parseInt(row.charAt(k)+"");
				}
			}
			out = false;
			dfs(1,1);
			if(out) {
				System.out.println("#"+i+" 1");
			}
			else {
				System.out.println("#"+i+" 0");
			}
		}
	}
	static void dfs(int y, int x) {
		int ny,nx;
		if(map[y][x]==3) {
			out=true;
			return;
		}
		for(int i=0;i<4;i++) {
			ny = y + dir[i][0];
            nx = x + dir[i][1];
            if (ny >= 0 && nx >= 0 && ny < map_size && nx < map_size && map[ny][nx] != 1 && !visited[ny][nx]) {
                //범위내, 벽아닌
                visited[ny][nx] = true;
                dfs(ny, nx);
                //돌아갈때 
                visited[ny][nx] = false;
            }
		}
	}
}
