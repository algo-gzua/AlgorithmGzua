package kakao7;

public class Solution {
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        String[][] str = new String[m][n];
        boolean[][] check = new boolean[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                str[i][j] = board[i].substring(j,j+1);
            }
        }
        boolean c = false;

        while(true) {

            c=false;

            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (!str[i][j].equals("0") && str[i][j].equals(str[i][j + 1]) && str[i][j].equals(str[i + 1][j]) && str[i][j].equals(str[i + 1][j + 1])) {
                        check[i][j] = check[i][j + 1] = check[i + 1][j] = check[i + 1][j + 1] = true;
                        c = true;
                    }
                }
            }

            if(!c){
                break;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (check[i][j] == true) {
                        str[i][j] = "0";
                        check[i][j] = false;
                    }
                }
            }
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                cnt = 0;
                for (int j = m - 1; j >= 0; j--) {
                    if (str[j][i].equals("0")) {
                        cnt++;
                    } else if (cnt != 0 && !str.equals("0")) {
                        str[j+cnt][i] = str[j][i];
                        str[j][i] = "0";
                    } else {
                        continue;
                    }
                }
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str[i][j].equals("0")) answer++;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        //String[] board = {"CCBDE","AAADE","AAABF","CCBBF"};
        String[] board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
        System.out.print(new Solution().solution(6,6,board));

    }
}
