package sw_3064;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st;

            int tc = Integer.parseInt(br.readLine());
            for(int i=1;i<=tc;i++){

                st = new StringTokenizer(br.readLine());
                int N = Integer.parseInt(st.nextToken());
                int M = Integer.parseInt(st.nextToken());

                int index = 1;
                while(index < N){
                    index *= 2;
                }

                st = new StringTokenizer(br.readLine());
                int[] arr = new int[index*2];
                for(int j=0;j<N;j++){
                    arr[index+j] = Integer.parseInt(st.nextToken());
                }

                for(int k=index;k<index*2;k++){
                    int ii = k/2;
                    while(ii>0){
                        arr[ii] += arr[k];
                        ii /= 2;
                    }
                }
                sb.append("#"+i);

                for(int k=0;k<M;k++){
                    st = new StringTokenizer(br.readLine());
                    int C = Integer.parseInt(st.nextToken());
                    int L = Integer.parseInt(st.nextToken());
                    int R = Integer.parseInt(st.nextToken());

                    if(C==1){
                        int x = index+L-1;
                        while(x>0){
                            arr[x] += R;
                            x /= 2;
                        }
                    }else{
                        int left = index+L-1;
                        int right = index+R-1;
                        int res = 0;

                        while(left<=right){

                            if(left%2==1){
                                res+=arr[left];
                                left++;
                            }
                            if(right%2==0){
                                res+=arr[right];
                                right--;
                            }
                            left/=2; right/=2;

                            if(left == right){
                                res += arr[left];
                                break;
                            }
                        }
                        sb.append(" "+res);
                    }
                }
                sb.append("\n");
            }
            bw.write(sb.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
