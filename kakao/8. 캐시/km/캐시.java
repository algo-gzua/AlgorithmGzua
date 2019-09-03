import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class Solution {
	public int solution(int cacheSize, String[] cities) {
		int answer = 0;
		
		LinkedList<String> list = new LinkedList<>();
		
		if (cacheSize == 0) {
			return cities.length * 5;
		}
		
		for (int i = 0; i < cities.length; ++i) {
			cities[i] = cities[i].toLowerCase();
			if (!list.contains(cities[i])) {
				if (list.size() >= cacheSize) {
					list.removeFirst();
				}
				
				list.addLast(cities[i]);
				answer += 5;
			} else {
				list.remove(list.indexOf(cities[i]));
				list.addLast(cities[i]);
				answer += 1;
			}
		}
		
		return answer;
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			int cacheSize = 3;
//			String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo",
//					"Seoul", "NewYork", "LA"};
			String[] cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
			
			System.out.println(solution(cacheSize, cities));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Solution().solve();
	}
}