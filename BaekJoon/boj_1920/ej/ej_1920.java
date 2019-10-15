import java.io.*;
import java.util.Arrays;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int num = Integer.parseInt(bf.readLine());
        int[] numArray = new int[num];
        String[] readLine = bf.readLine().split(" ");
        for(int i=0; i<num; i++){
            numArray[i] = Integer.parseInt(readLine[i]);
        }
        Arrays.sort(numArray);

        int num2 = Integer.parseInt(bf.readLine());
        int[] existNumArray = new int[num2];
        String[] readLine2 = bf.readLine().split(" ");
        for(int i=0; i<num2; i++){
            existNumArray[i] = Integer.parseInt(readLine2[i]);
        }

        for(int i=0; i<existNumArray.length; i++){
            existNumArray[i] = existNum(existNumArray[i], numArray);
        }
        for(int i=0; i<existNumArray.length; i++){
            bw.write(existNumArray[i]+"\n");
        }
        bw.flush();
        bw.close();
    }

    private static int existNum(int existValue, int array[]){
        int mid = 0;
        int left = 0;
        int right = array.length-1;

        while(right >= left){
            mid = (right + left) / 2;
            if(existValue == array[mid]){
                return 1;
            }
            if(existValue > array[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
}