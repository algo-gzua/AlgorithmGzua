package kakao11;

public class Solution {
    //n진법 * 숫자의 개수 t * 인원 m * 순서 p
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        String str = "";
        String str2;

        for(int i=0;i<t*m;i++){
            int num=i;
            str2="";
            while(true){
                int x= num%n;
                char c;
                if(x >= 10){
                    x = x + 55;
                    c = (char) x;
                }else{
                    c = java.lang.Character.forDigit(x,10);
                }

                if(num/n==0){
                    str2 = c + str2;
                    str = str + str2;
                    break;
                }
                str2 = c + str2;
                num = num / n;
            }

        }
        int turn = p-1;
        for(int i=0;i<t;i++){
            answer = answer + str.charAt(turn);
            turn += m;
        }

        return answer;
    }

    public static void main(String[] args) {
        System.out.print(new Solution().solution(16,16,2,1));
    }
}
