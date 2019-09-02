import java.util.ArrayList;

public class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        ArrayList<String> str1List = new ArrayList<>();
        for (int i = 0; i < str1.length() - 1; ++i) {
            if (str1.charAt(i) < 'a' || str1.charAt(i) > 'z' || str1.charAt(i + 1) < 'a' || str1.charAt(i + 1) > 'z') {
                continue;
            }

            String temp = str1.charAt(i) + "" + str1.charAt(i + 1);
            str1List.add(temp);
        }

        ArrayList<String> gyoList = new ArrayList<>();
        ArrayList<String> habList = new ArrayList<>();

        for (int i = 0; i < str2.length() - 1; ++i) {
            if (str2.charAt(i) < 'a' || str2.charAt(i) > 'z' || str2.charAt(i + 1) < 'a' || str2.charAt(i + 1) > 'z') {
                continue;
            }

            String temp = str2.charAt(i) + "" + str2.charAt(i + 1);

            boolean isCheck = false;
            for (int a = 0; a < str1List.size(); ++a) {
                if (str1List.get(a).equals(temp)) {
                    gyoList.add(temp);
                    habList.add(temp);
                    str1List.set(a, "-");
                    isCheck = true;
                    break;
                }
            }

            if (!isCheck) {
                habList.add(temp);
            }
        }

        for (String s : str1List) {
            if (!s.equals("-")) {
                habList.add(s);
            }
        }

        if (gyoList.size() == 0 && habList.size() == 0) {
            answer = 65536;
        } else {
            double d = ((double) gyoList.size() / habList.size()) * 65536;

            answer = (int) Math.floor(d);
        }

        return answer;
    }

    public static void main(String[] args) {
//        String str1 = "FRANCE";
//        String str2 = "french";

//        String str1 = "handshake";
//        String str2 = "shake hands";

        String str1 = "E=M*C^2";
        String str2 = "e=m*c^2";

        System.out.println(new Solution().solution(str1, str2));
    }
}
