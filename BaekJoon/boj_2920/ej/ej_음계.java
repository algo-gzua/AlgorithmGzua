import java.io.*;
import java.util.Arrays;

public class Main {

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int[] ascending={1,2,3,4,5,6,7,8};
        int[] descending={8,7,6,5,4,3,2,1};
        int[] value = new int[8];

        String data = bf.readLine();
        String[] dataArray = data.split(" ");
        for(int i=0; i<dataArray.length; i++){
            value[i]=Integer.parseInt(dataArray[i]);
        }

        if(Arrays.equals(ascending, value)){
            bw.write("ascending");
        } else if(Arrays.equals(descending,value)) {
            bw.write("descending");
        } else {
            bw.write("mixed");
        }

        bw.flush();
        bw.close();
    }
}