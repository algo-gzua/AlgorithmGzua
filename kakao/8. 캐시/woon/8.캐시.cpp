#include<iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int size = cities.size();
	if (cacheSize == 0) {
		return size * 5;
	}

	// 소문자->대문자바꾸기
	for (int i = 0; i < size; i++) {
		int len = cities[i].size();

		for (int j = 0; j < len; j++) {
			if ('a' <= cities[i][j] && cities[i][j] <= 'z') {
				cities[i][j] = cities[i][j] - 32;
			}
		}
	}

	deque<string> dq;
	string tmp;

	//처음은 무조건 캐시 miss
	dq.push_front(cities[0]);
	int time = 5;

	for (int i = 1; i < size; i++) {
		int len = dq.size();

		for (int j = 0; j < len; j++) {

			//캐시 사이즈보다 dq가 작을 경우
			if (cacheSize > len) {
				//캐시 hit
				if (dq[j] == cities[i]) {
					time = time + 1;
					for (int k = j; k > 0; k--) {
						tmp = dq[k];
						dq[k] = dq[k - 1];
						dq[k - 1] = tmp;
					}
					break;
				}
				//캐시 miss
				else {
					if (j + 1 == len) {
						dq.push_front(cities[i]);
						time = time + 5;
					}
					else {
						continue;
					}
				}
			}
			//캐시 사이즈랑 dq사이즈가 같을때
			else {
				//캐시 hit
				if(dq[j] == cities[i]){
					time = time + 1;
					for (int k = j; k > 0; k--) {
						tmp = dq[k];
						dq[k] = dq[k - 1];
						dq[k - 1] = tmp;
					}
					break;
				}
				//캐시 miss
				else {
					if (j + 1 == len) {
						dq.push_front(cities[i]);
						dq.pop_back();
						time = time + 5;
					}
					else {
						continue;
					}
				}
			}	
		}
	}

	answer = time;
	return answer;
}



int main() {

	vector<string> v;
	int cacheSize = 2;


	v.push_back("Jeju");
	v.push_back("Pangyo");
	//v.push_back("Seoul");
	v.push_back("NewYork");	
	//v.push_back("LA");
	//v.push_back("Jeju");
	//v.push_back("Pangyo");
	//v.push_back("Seoul");
	v.push_back("newyork");
	//v.push_back("LA");


	cout << solution(cacheSize, v);

	return 0;
}