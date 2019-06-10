import java.io.*;
import java.util.Stack;

class Node {
    int y;
    int x;

    Node() {

    }

    Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            char[][] board;
            boolean[][] visit;
            StringBuilder sb = new StringBuilder();
            int[][] direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (int t = 1; t <= 10; ++t) {
                int tc = Integer.parseInt(br.readLine());
                board = new char[100][100];
                visit = new boolean[100][100];

                // input
                Node start = new Node();
                Node end = new Node();
                for (int i = 0; i < 100; ++i) {
                    String s = br.readLine();

                    for (int j = 0; j < 100; ++j) {
                        board[i][j] = s.charAt(j);

                        if (board[i][j] == '2') {
                            start = new Node(i, j);
                        } else if (board[i][j] == '3') {
                            end = new Node(i, j);
                        }
                    }
                }

                Stack<Node> stack = new Stack<>();
                stack.push(start);
                visit[start.y][start.x] = true;

                boolean isCheck = false;
                while (!stack.isEmpty()) {
                    Node n = stack.pop();

                    if (n.y == end.y && n.x == end.x) {
                        isCheck = true;
                        break;
                    }

                    // 4방향
                    for (int d = 0; d < 4; ++d) {
                        int y = n.y + direction[d][0];
                        int x = n.x + direction[d][1];

                        if (x < 0 || y < 0 || x >= 100 || y >= 100) {
                            continue;
                        }

                        if (board[y][x] != '1' && !visit[y][x]) {
                            stack.push(new Node(y, x));
                            visit[y][x] = true;
                        }
                    }
                }

                if (isCheck) {
                    sb.append("#").append(tc).append(" 1\n");
                } else {
                    sb.append("#").append(tc).append(" 0\n");
                }
            }

            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}
