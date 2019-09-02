#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool check(string s) {
	for (int i = 0; i < 2; i++) {
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')) {
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] += 32;
			continue;
		}
		else
			return false;
	}
	return true;
}

map<string, int > m1, m2, m3;

int solution(string str1, string str2) {
	int s1_size = str1.size();
	int s2_size = str2.size();

	for (int i = 0; i < s1_size - 1; i++) {
		string str = str1.substr(i, 2);
		str[0] = toupper(str[0]);
		str[1] = toupper(str[1]);
		if (check(str)) {
			if (m1.find(str) == m1.end()) {
				m1.insert({ str,1 });
				m3.insert({ str,1 });
			}
			else {
				m1[str]++;
				m3[str]++;
			}
		}
	}

	for (int i = 0; i < s2_size - 1; i++) {
		string str = str2.substr(i, 2);
		str[0] = toupper(str[0]);
		str[1] = toupper(str[1]);
		if (check(str)) {
			if (m2.find(str) == m2.end())
				m2.insert({ str,1 });
			else
				m2[str]++;
		}
	}

	if (m1.size() == 0 && m2.size() == 0)
		return 65536;
	int m_sum = 0;
	int m_and = 0;
	for (auto it = m2.begin(); it != m2.end(); it++) {
		if (m3.find(it->first) == m3.end()) {
			m3.insert({ it->first,it->second });		
		}
		else {
			m_and += m3[it->first] < it->second ? m3[it->first] : it->second;
			m3[it->first] = m3[it->first] < it->second ? it->second : m3[it->first];
		}
	}
	
	for (auto it = m3.begin(); it != m3.end(); it++) {
		m_sum += it->second;
	}
	int res = (65536 * m_and) / m_sum ;
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);

	string s1 = "FRANCE";
	string s2 = "french";

	

	cout << solution(s1, s2);

}