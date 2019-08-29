#include <string>
#include <vector>
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<string> cache;
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	int c_s = cities.size();
	
	if (cacheSize == 0)
		return 5 * c_s;
	for (string c : cities) {
		transform(c.begin(), c.end(), c.begin(), ::toupper);
		int cache_size = cache.size();
		bool toggle = false;
		for (int i = 0; i < cache_size; i ++) {
			if (cache[i] == c && !toggle) {
				toggle = true;
				answer += 1;
				continue;
			}
			if (toggle) {
				cache[i - 1] = cache[i];
			}
		}
		if (toggle) {
			cache.pop_back();
			cache.push_front(c);
		}
		if (!toggle) {
			if (cache.size() == cacheSize) {
				cache.pop_back();
			}

			answer += 5;
			cache.push_front(c);
		}
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);

	vector<string> city;
	city.push_back("NewYork");
	city.push_back("Jeju");
	city.push_back("newyork");
	city.push_back("Pangyo");
	

	cout << solution(2, city);
}
