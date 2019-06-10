package date_190508.sw_1223;

import java.io.*;
import java.util.Stack;

public class Solution {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            StringBuilder sb = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();

            for(int i=1;i<=10;i++){
                sb.setLength(0);
                int num = Integer.parseInt(br.readLine());
                String str = br.readLine();
                Stack s = new Stack();
                String[] arr = new String[num];
                arr = str.split("");

                //후위연산자로 만들기
                for(int j=0;j<arr.length;j++){
                    if(!arr[j].equals("+") && !arr[j].equals("*")){
                        sb.append(arr[j]);
                    }
                    else{
                        if(s.isEmpty()){
                            s.push(arr[j]);
                        }
                        //peek > 현재연산자
                        else if(opPriority(s.peek().toString()) >
                                opPriority(arr[j])){
                            while(!s.isEmpty()){
                                sb.append(s.pop());
                            }
                            s.push(arr[j]);
                        }
                        //peek == 현재 연산자
                        else if(opPriority(s.peek().toString())==
                                opPriority(arr[j])){
                            sb.append(s.pop());
                            s.push(arr[j]);
                        }
                        //peek < 현재 연산자
                        else{
                            s.push(arr[j]);
                        }
                    }
                }
                while(!s.isEmpty()){
                    sb.append(s.pop());
                }

                //후위연산자 계산
                str = sb.toString();
                arr = str.split("");
                int a,b;
                //피연산자는 스택에 무조건 입력, 연산자를 만나면 피연산자 두개를 꺼내어 연산한 결과를 push
                for(int k=0;k<arr.length;k++){
                    if(!arr[k].equals("+") && !arr[k].equals("*")){
                        s.push(arr[k]);
                    }
                    else if(arr[k].equals("+")){
                        a = Integer.parseInt(s.pop().toString());
                        b = Integer.parseInt(s.pop().toString());
                        s.push(a+b);
                    }
                    else if(arr[k].equals("*")){
                        a = Integer.parseInt(s.pop().toString());
                        b = Integer.parseInt(s.pop().toString());
                        s.push(a*b);
                    }
                }
                sb2.append("#"+i+" "+s.pop()+"\n");
            }
            bw.write(sb2.toString());
            bw.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static int opPriority(String op){
        if(op.equals("+")){
            return 1;
        }
        if(op.equals("*")){
            return 2;
        }
        return 0;
    }
}
