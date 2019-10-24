import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int N = Integer.parseInt(br.readLine());

            String[] s = br.readLine().split(" ");
            int[] arr = new int[N];

            for (int i = 0; i < N; ++i) {
                arr[i] = Integer.parseInt(s[i]);
            }

            ArrayList<Integer> arrayList = new ArrayList<>();
            arrayList.add(-1);

            for (int i = 0; i < N; ++i) {
                if (arrayList.get(arrayList.size() - 1) < arr[i]) {
                    arrayList.add(arr[i]);
                } else {
                    // lowerBound
                    int left = 0;
                    int right = arrayList.size() - 1;
                    int index = 0;
                    while (left <= right) {
                        int mid = (left + right) / 2;

                        if (arrayList.get(mid) < arr[i]) {
                            left = mid + 1;
                        } else {
                            index = mid;
                            right = mid - 1;
                        }
                    }

                    arrayList.set(index, arr[i]);
                }
            }

            System.out.println(arrayList.size() - 1);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}