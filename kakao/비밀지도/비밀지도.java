import java.util.Arrays;

public class Solution {
	public String[] solution(int n, int[] arr1, int[] arr2) {
	      String[] answer = new String[n];
	      
	      char[][] board = new char[n][n];
	      
	      for (int i = 0; i < n; ++i) {
	    	  for (int j = 0; j < n; ++j) {
	    		  if ((arr1[i] & (1 << j)) != 0) {
	    			  board[i][j] = '#';
	    		  }
	    		  
	    		  if ((arr2[i] & (1 << j)) != 0) {
	    			  board[i][j] = '#';
	    		  }
	    	  }
	      }
	      
	      for (int i = 0; i < n; ++i) {
	    	  String temp = "";
	    	  for (int j = 0; j < n; ++j) {
	    		  if (board[i][j] == '#') {
	    			  temp = board[i][j] + temp;
	    		  } else {
	    			  temp = " " + temp;
	    		  }
	    	  }
	    	  answer[i] = temp;
	      }
	      
	      return answer;
	  }
	
	public static void main(String[] args) {
		int[] arr1 = {9, 20, 28, 18, 11};
		int[] arr2 = {30, 1, 21, 17, 28};
		
		System.out.println(Arrays.toString(new Solution().solution(5, arr1, arr2)));
	}
}