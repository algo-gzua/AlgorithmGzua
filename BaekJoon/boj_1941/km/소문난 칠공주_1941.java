import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    final int SIZE = 5;
    int[][] direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    char[][] arr;
    boolean[][] visit;
    boolean[][] linkVisit;
    int[] student;
    HashMap<Character, Integer> map;
    int result;

    private void checkLink(int y, int x) {
        for (int i = 0; i < 4; ++i) {
            int newY = y + direct[i][0];
            int newX = x + direct[i][1];

            if (newY >= SIZE || newY < 0 || newX >= SIZE || newX < 0) {
                continue;
            }

            if (!linkVisit[newY][newX]) {
                continue;
            }

            linkVisit[newY][newX] = false;
            checkLink(newY, newX);
        }
    }

    private void dfs(int y, int x, int count) {
        if (count == 7) {
            int linkCount = 0;

            for (int i = 0; i < SIZE; ++i) {
                linkVisit[i] = visit[i].clone();
            }

            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    if (linkVisit[i][j]) {
                        checkLink(i, j);
                        linkCount++;
                    }
                }
            }

            if (linkCount != 1) {
                return;
            }

            if (student[0] > student[1]) {
                result++;
            }
            return;
        }

        for (int i = y; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (i == y && j <= x) {
                    continue;
                }

                student[map.get(arr[i][j])]++;
                visit[i][j] = true;
                dfs(i, j, count + 1);
                visit[i][j] = false;
                student[map.get(arr[i][j])]--;
            }
        }
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            arr = new char[SIZE][SIZE];
            visit = new boolean[SIZE][SIZE];
            linkVisit = new boolean[SIZE][SIZE];
            student = new int[2]; // 0이 이다솜, 1이 임도연 (이다솜이 더 많아야함)
            map = new HashMap<>();
            result = 0;

            map.put('S', 0);
            map.put('Y', 1);

            for (int i = 0; i < SIZE; ++i) {
                String input = br.readLine();
                for (int j = 0; j < SIZE; ++j) {
                    arr[i][j] = input.charAt(j);
                }
            }

            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    student[map.get(arr[i][j])]++;
                    visit[i][j] = true;
                    dfs(i, j, 1);
                    visit[i][j] = false;
                    student[map.get(arr[i][j])]--;
                }
            }

            System.out.println(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}