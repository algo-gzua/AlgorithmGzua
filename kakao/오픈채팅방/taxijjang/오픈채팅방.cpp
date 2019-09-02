#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<queue>
#include<sstream>
using namespace std;

map<string, string> m;
queue<pair<string, string>> q;
vector<string> solution(vector<string> record) {
	vector<string> answer;

	for (string r : record) {
		vector<string> arr;
		stringstream ss(r);
		string k;

		while (ss >> k) {
			arr.push_back(k);
		}

		if (arr[0] == "Enter") {
			q.push({ arr[1],arr[0] });
			if (m.find(arr[1]) == m.end())
				m.insert({ arr[1],arr[2] });
			m[arr[1]] = arr[2];
		}
		else if (arr[0] == "Leave") {
			q.push({ arr[1],arr[0] });
		}
		else if (arr[0] == "Change") {
			m[arr[1]] = arr[2];
		}

	}
	//q 유저 아이디 , 입출력
	while (!q.empty()) {
		pair<string, string> p = q.front();
		string mes ="";
		q.pop();

		if (p.second == "Enter") {
			mes = m[p.first] + "님이 들어왔습니다.";
			answer.push_back(mes);
		}
		else if (p.second == "Leave") {
			mes = m[p.first] + "님이 나갔습니다.";
			answer.push_back(mes);
		}
		
	}
	getchar();
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);

	vector<string> record;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	for (auto it = solution(record).begin(); it != solution(record).end(); it++) {
		cout << *it << "\n";
	}
}