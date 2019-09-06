import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Node {
	String head;
	String number;
	String tail;
	int index;
	
	Node (String head, String number, String tail, int index) {
		this.head = head;
		this.number = number;
		this.tail = tail;
		this.index = index;
	}
}

public class Solution {
	public String[] solution(String[] files) {
		String[] answer = {};
		
		ArrayList<Node> list = new ArrayList<>();
		for (int index = 0; index < files.length; ++index) {
			String s = files[index];
			int headIndex = 0;
			int numberIndex = 0;
			String head = "";
			String number = "";
			String tail = "";
			
			for (int i = 0; i < s.length(); ++i) {
				if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
					headIndex = i - 1;
					break;
				} else {
					head += s.charAt(i);
				}
			}
			
			boolean isEnd = false;
			for (int i = headIndex + 1; i < s.length(); ++i) {
				if (!(s.charAt(i) >= '0' && s.charAt(i) <= '9')) {
					numberIndex = i - 1;
					isEnd = true;
					break;
				} else {
					number += s.charAt(i);
				}
			}
			
			if (isEnd) {
				for (int i = numberIndex + 1; i < s.length(); ++i) {
					tail += s.charAt(i);
				}
			}
			
			list.add(new Node(head, number, tail, index));
		}
		
		Collections.sort(list, (n1, n2) -> {
			if (n1.head.compareToIgnoreCase(n2.head) > 0) {
				return 1;
			} else if (n1.head.compareToIgnoreCase(n2.head) == 0) {
				if (Integer.parseInt(n1.number) > Integer.parseInt(n2.number)) {
					return 1;
				} else if (Integer.parseInt(n1.number) == Integer.parseInt(n2.number)) {
					if (n1.index > n2.index) {
						return 1;
					}
				}
			}
			
			return -1;
		});
		
		answer = new String[list.size()];
		
		for (int i = 0; i < list.size(); ++i) {
			answer[i] = list.get(i).head + list.get(i).number + list.get(i).tail;
		}
		
		return answer;
	}

	public static void main(String[] args) {
		String[] files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
//		String[] files = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
//		String[] files = {"F-1", "F-2", "B-33"};
		System.out.println(Arrays.toString(new Solution().solution(files)));
	}
}