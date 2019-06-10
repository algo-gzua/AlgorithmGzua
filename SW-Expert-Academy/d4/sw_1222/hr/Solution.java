package date_190501.sw_1222;

import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringBuilder sb = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();

            for(int i=1;i<=2;i++) {
                int num = Integer.parseInt(br.readLine());
                String str = br.readLine();
                Stack s = new Stack();
                String[] arr = new String[num];

                arr = str.split("");

                for(int j=0; j<num; j++){
                    if(s.isEmpty() && !arr[j].equals("+")){
                        sb.append(arr[j]);
                    }
                    else if(s.isEmpty() && arr[j].equals("+") ) {
                        s.push(arr[j]);
                    }
                    else {
                        s.push(arr[j]);
                        while (!s.isEmpty()) {
                            sb.append(s.pop());
                        }
                    }
                }
                str=sb.toString(); //후위식 완성
                sb.setLength(0);
                arr = str.split("");

                int res=0;
                for(int k=0;k<num;k++){
                    if(s.isEmpty()){
                        s.push(arr[k]);
                        s.push(arr[k]);
                    }
                    else if(arr[k].equals("+")){
                        int op1 = Integer.parseInt(s.pop().toString());
                        int op2 = Integer.parseInt(s.pop().toString());
                        res = op1 + op2;
                        s.push(res);
                    }
                    else{
                        s.push(arr[k]);
                    }
                }
                sb2.append("#"+i+" "+res+"\n");
            }
            bw.write(sb2.toString());
            bw.flush();

        }catch(IOException e) {
            e.printStackTrace();
        }
    }
}
