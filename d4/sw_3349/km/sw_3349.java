import java.io.*;

public class Solution {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());

            StringBuilder sb = new StringBuilder();
            for (int t = 1; t <= T; ++t) {
                String[] s = br.readLine().split(" ");
//                int W = Integer.parseInt(s[0]);
//                int H = Integer.parseInt(s[1]);
                int N = Integer.parseInt(s[2]);

                String[] temp;

                temp = br.readLine().split(" ");
                int currX = Integer.parseInt(temp[0]);
                int currY = Integer.parseInt(temp[1]);

                int result = 0;
                for (int n = 1; n < N; ++n) {
                    temp = br.readLine().split(" ");

                    int newX = Integer.parseInt(temp[0]);
                    int newY = Integer.parseInt(temp[1]);

                    // x가 작고 y가 작을 때 y값 맞을 때 까지 x, y + 1 이후 모자란거 ++
                    if (currX < newX && currY < newY) {
                        while (currX != newX && currY != newY) {
                            currX++;
                            currY++;
                            result++;
                        }

                        while (currX != newX) {
                            currX++;
                            result++;
                        }

                        while (currY != newY) {
                            currY++;
                            result++;
                        }
                    }
                    // x가 작고 y가 클 때	 y값을 맞을 때 까지 y - 1 이후 x++
                    else if (currX < newX && currY > newY) {
                        while (currY != newY) {
                            currY--;
                            result++;
                        }

                        while (currX != newX) {
                            currX++;
                            result++;
                        }
                    }
                    // x가 크고 y가 작을 때 y값 맞을 때 까지 y + 1 이후 x--
                    else if (currX > newX && currY < newY) {
                        while (currY != newY) {
                            currY++;
                            result++;
                        }

                        while (currX != newX) {
                            currX--;
                            result++;
                        }
                    }
                    // x가 크고 y도 클 때	 y값 맞을 때 까지 x, y - 1 이후 모자란거 --
                    else if (currX > newX && currY > newY){
                        while (currX != newX && currY != newY) {
                            currX--;
                            currY--;
                            result++;
                        }

                        while (currX != newX) {
                            currX--;
                            result++;
                        }

                        while (currY != newY) {
                            currY--;
                            result++;
                        }
                    }
                    // y값만 다를 때
                    else if (currX == newX && currY != newY) {
                        while (currY > newY) {
                            currY--;
                            result++;
                        }

                        while (currY < newY) {
                            currY++;
                            result++;
                        }
                    }
                    // x값만 다를 때
                    else if (currX != newX && currY == newY) {
                        while (currX > newX) {
                            currX--;
                            result++;
                        }

                        while (currX < newX) {
                            currX++;
                            result++;
                        }
                    }

                    currX = newX;
                    currY = newY;
                }

                System.out.println("#" + t + " " + result);

            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Solution().solve();
    }
}