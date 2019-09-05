package kakao8;

import java.io.*;
import java.util.*;

public class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;

        if(cacheSize == 0){
            return cities.length * 5;
        }

        Map cache = new LinkedHashMap(cacheSize+1,.75F,true){
            public boolean removeEldestEntry(Map.Entry eldest){
                return size() > cacheSize;
            }
        };

        for(String key : cities){
            if(cache.containsKey(key.toLowerCase())){
                cache.put(key.toLowerCase(),0);
                answer += 1;
            }else{
                cache.put(key.toLowerCase(),0);
                answer += 5;
            }
        }
        return answer;
    }

    public static void main(String[] args) {

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int cacheSize = 3;
            String[] cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
            System.out.println(new Solution().solution(cacheSize, cities));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
