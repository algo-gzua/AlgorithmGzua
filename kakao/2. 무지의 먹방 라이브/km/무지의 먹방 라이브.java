import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
	public int solution(int[] food_times, long k) {
		int size = food_times.length;
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < size; ++i) {
			list.add(food_times[i]);
		}
		
		Collections.sort(list);
		
		int height = 0;
		for (int i = 0; i < size; ++i) {
			int time = list.get(i);
			
			for (int j = 0; j < time; ++j) {
				if (height >= time) {
					break;
				}
				
				if (size - i < k) {
					height++;
					k -= (size - i);
				} else {
					for (int a = 0; a < size; ++a) {
						if (food_times[a] <= height) {
							continue;
						}

						food_times[a]--;
						k--;
						
						if (k == 0) {
							int index = (a + 1) % size;
							for (int q = 0; q < size; ++q) {
								if (food_times[index] <= height) {
									index = (index + 1) % size;
									continue;
								}
								
								return index + 1;
							}
						}
					}
					i = size;
					break;
				}
			}
		}
		
		return -1;
	}
	
	private void solve() {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
//			int[] food_times = {3, 1, 2};
//			long k = 5;
			
			int[] food_times = {1, 2, 3, 4, 5, 6};
			long k = 21;
			
			System.out.println(solution(food_times, k));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Solution().solve();
	}
}