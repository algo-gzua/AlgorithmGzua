
package com.company;
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int[][] maze;
    public static int n, m;

    static class Node {
        int y;
        int x;
        int dis;

        Node(int y, int x, int dis) {
            this.y = y;
            this.x = x;
            this.dis = dis;
        }
    }

    public static void main(String[] args) throws IOException {
        int[][] direction = {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        String inputNum = bf.readLine();
        String[] inputNumArray = inputNum.split(" ");
        n = Integer.parseInt(inputNumArray[0]);
        m = Integer.parseInt(inputNumArray[1]);

        int destinationY = n - 1;
        int destinationX = m - 1;

        maze = new int[n][m];
        for (int i = 0; i < n; i++) {
            String array = bf.readLine();
            for (int j = 0; j < m; j++) {
                maze[i][j] = Integer.parseInt(String.valueOf(array.charAt(j)));
            }
        }

        bw.write(direction(direction, destinationY, destinationX) + "\n");
        bw.flush();
        bw.close();
    }

    public static int direction(int[][] direction, int destinationY, int destinationX) throws IOException {
        int distance = 0;

        boolean[][] visit = new boolean[n][m];

        Deque<Node> queue = new ArrayDeque<Node>();

        queue.add(new Node(0, 0, 1));
        visit[0][0] = true;

        while (!queue.isEmpty()) {
            Node node = queue.pop();
            distance = node.dis+1;

            if (node.y == destinationY && node.x == destinationX) {
                distance--;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int newY = node.y + direction[i][0];
                int newX = node.x + direction[i][1];

                if (newY < 0 || newY >= n || newX < 0 || newX >= m) {
                    continue;
                }

                if (visit[newY][newX]) {
                    continue;
                }

                if (maze[newY][newX] == 1) {
                    visit[newY][newX] = true;
                    queue.add(new Node(newY, newX, distance));
                }
            }
        }
        return distance;
    }
}