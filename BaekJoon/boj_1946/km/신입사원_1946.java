import java.io.*;
import java.util.Arrays;

class Node {
    int document;
    int interview;

    Node (int document, int interview) {
        this.document = document;
        this.interview = interview;
    }
}

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int T = Integer.parseInt(br.readLine());
            StringBuilder sb = new StringBuilder();

            for (int t = 1; t <= T; ++t) {
                int N = Integer.parseInt(br.readLine());
                Node[] arr = new Node[N];

                String[] s;
                for (int i = 0; i < N; ++i) {
                    s = br.readLine().split(" ");
                    arr[i] = new Node(Integer.parseInt(s[0]), Integer.parseInt(s[1]));
                }

                Arrays.sort(arr, (n1, n2) -> {
                    return Integer.valueOf(n1.document).compareTo(n2.document);
                });

                int count = 1;
                int interview = arr[0].interview;

                for (int i = 1; i < N; ++i) {
                    if (arr[i].interview < interview) {
                        count++;
                        interview = arr[i].interview;
                    }
                }

                sb.append(count).append("\n");
            }
            bw.write(sb.toString());
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}
