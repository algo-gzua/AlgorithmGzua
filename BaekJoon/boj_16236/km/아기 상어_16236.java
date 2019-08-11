import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Shark {
    int i;
    int j;
    int size;
    int distance;
    int remain;

    Shark(int i, int j, int size, int remain, int distance) {
        this.i = i;
        this.j = j;
        this.size = size;
        this.remain = remain;
        this.distance = distance;
    }
}

public class Main {
    int N;
    int[][] board;
    int sharkI;
    int sharkJ;
    int sharkSize;
    int sharkRemain;
    int[][] direct = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    boolean[][] isVisit;
    int result;

    private boolean bfs() {
        for (int i = 0; i < N; ++i) {
            Arrays.fill(isVisit[i], false);
        }

        Shark shark = new Shark(sharkI, sharkJ, sharkSize, sharkRemain, 0);
        isVisit[sharkI][sharkJ] = true;

        Queue<Shark> q = new LinkedList<>();

        q.add(shark);

        int minI = -1;
        int minJ = -1;
        int minSize = -1;
        int minRemain = -1;
        int minDistance = -1;


        while (!q.isEmpty()) {
            Shark babyShark = q.poll();

            for (int i = 0; i < 4; ++i) {
                int newI = babyShark.i + direct[i][0];
                int newJ = babyShark.j + direct[i][1];

                if (newI >= 0 && newI < N && newJ >= 0 && newJ < N && !isVisit[newI][newJ]) {
                    if (board[newI][newJ] != 0) {
                        if (board[newI][newJ] < babyShark.size) {
                            if (minI == -1) {
                                minI = newI;
                                minJ = newJ;

                                if (babyShark.remain - 1 == 0) {
                                    minSize = babyShark.size + 1;
                                    minRemain = minSize;
                                } else {
                                    minSize = babyShark.size;
                                    minRemain = babyShark.remain - 1;
                                }
                                minDistance = babyShark.distance + 1;

                            } else if (minDistance >= babyShark.distance + 1) {
                                if ((minI > newI) || (minI == newI && minJ > newJ)) {
                                    minI = newI;
                                    minJ = newJ;

                                    if (babyShark.remain - 1 == 0) {
                                        minSize = babyShark.size + 1;
                                        minRemain = minSize;
                                    } else {
                                        minSize = babyShark.size;
                                        minRemain = babyShark.remain - 1;
                                    }
                                    minDistance = babyShark.distance + 1;
                                }
                            }

                            isVisit[newI][newJ] = true;

                        } else if (board[newI][newJ] == babyShark.size) {
                            q.offer(new Shark(newI, newJ, babyShark.size, babyShark.remain, babyShark.distance + 1));
                            isVisit[newI][newJ] = true;
                        }
                    } else if (board[newI][newJ] == 0) {
                        q.offer(new Shark(newI, newJ, babyShark.size, babyShark.remain, babyShark.distance + 1));
                        isVisit[newI][newJ] = true;
                    }
                }
            }
        }

        if (minI != -1) {
            sharkI = minI;
            sharkJ = minJ;

            sharkSize = minSize;
            sharkRemain = minRemain;

            result += minDistance;

            board[minI][minJ] = 0;
            return true;
        }

        return false;
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(br.readLine());
            board = new int[N][N];
            isVisit = new boolean[N][N];
            result = 0;

            for (int i = 0; i < N; ++i) {
                String[] s = br.readLine().split(" ");
                for (int j = 0; j < N; ++j) {
                    board[i][j] = Integer.parseInt(s[j]);

                    if (board[i][j] == 9) {
                        sharkI = i;
                        sharkJ = j;
                        sharkSize = 2;
                        sharkRemain = sharkSize;
                        board[i][j] = 0;
                    }
                }
            }

            while (bfs()) ;

            System.out.println(result);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}
