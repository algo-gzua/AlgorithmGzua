import java.util.ArrayList;
import java.util.HashSet;

public class Solution {

	public int solution(String[][] relation) {
		ArrayList<Integer> candidate = new ArrayList<>();
		
		int attribute = relation[0].length;
		for (int i = 0; i < (1 << attribute); ++i) {
			ArrayList<Integer> list = new ArrayList<>();
			
			for (int j = 0; j < attribute; ++j) {
				boolean isExist = false;
				if ((i & (1 << j)) != 0) {
					for (int key : candidate) {
						if ((i & key) == key) {
							isExist = true;
							break;
						}
					}
					
					if (isExist) {
						list.clear();
						break;
					}
					list.add(j);
				}
			}
			
			HashSet<String> set = new HashSet<>();
			
			for (int j = 0; j < relation.length; ++j) {
				String temp = "";
				for (int key : list) {
					temp += relation[j][key];
				}
				
				if (!temp.equals("")) {					
					set.add(temp);
				}
			}
			
			if (set.size() == relation.length) {
				candidate.add(i);
			}
		}
		
		return candidate.size();
    }
	
	public static void main(String[] args) {
		String[][] relation = {{"100","ryan","music","2"}, {"200","apeach","math","2"},
				{"300","tube","computer","3"}, {"400","con","computer","4"},
				{"500","muzi","music","3"}, {"600","apeach","music","2"}};
		
		System.out.println(new Solution().solution(relation));
	}
}
