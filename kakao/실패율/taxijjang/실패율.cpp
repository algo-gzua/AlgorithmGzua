#include<algorithm>
#include <string>
#include <vector>
#include<iostream>

using namespace std;

int arr[510];

vector<pair<double, int>> p;
bool cop(pair<double, int> p1, pair<double, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}
vector<int> solution(int N, vector<int> stages) {
	

	for (auto it = stages.begin(); it != stages.end(); it++) {
		arr[*it] ++;
	}

	int size = stages.size();
	for (int i = 1; i <= N; i++) {
		p.push_back({ (double)arr[i] / (double) size, i });
		size -= arr[i];
	}

	sort(p.begin(), p.end(),cop);
	vector<int> answer;

	for (auto it = p.begin(); it != p.end(); it++) {
		answer.push_back(it->second);
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	
	vector<int> s;
	s.push_back(2);
	s.push_back(1);
	s.push_back(2);
	s.push_back(6);
	s.push_back(2);
	s.push_back(4);
	s.push_back(3);
	s.push_back(3);

	vector<int> v = solution(5, s);

	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << "\n";
	}
}