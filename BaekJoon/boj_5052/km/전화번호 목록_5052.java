import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    class Node {
        Node[] address;
        boolean isEnd;

        Node () {
            address = new Node[10];
            isEnd = false;
        }

        void insert(String item, int index) {
            if (item.length() == index) {
                isEnd = true;
                return;
            }

            int curr = item.charAt(index) - '0';
            if (address[curr] == null) {
                address[curr] = new Node();
            }
            address[curr].insert(item, index + 1);
        }

        boolean find(String item, int index) {
            if (item.length() == index) {
                return false;
            } else if(isEnd) {
                return true;
            }

            return address[item.charAt(index) - '0'].find(item, index + 1);
        }
    }

    private void solve() {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(br.readLine());

            for (int t = 1; t <= T; ++t) {
                int n = Integer.parseInt(br.readLine());
                Node root = new Node();
                String[] s = new String[n];

                for (int i = 0; i < n; ++i) {
                    s[i] = br.readLine();

                    root.insert(s[i], 0);
                }

                boolean isSuccess = true;
                for (int i = 0; i < n; ++i) {
                    if (root.find(s[i], 0)) {
                        isSuccess = false;
                        break;
                    }
                }

                if (isSuccess) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}
