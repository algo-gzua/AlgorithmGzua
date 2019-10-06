#include<iostream>
#include<string>
#include<map>

using namespace std;

map <char, int > m;
int main(void) {
	string s; cin >> s;
	
	int m_cnt = 0;
	char res = '?';
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
		if (m.find(s[i]) == m.end())
			m.insert({ s[i],1 });
		else 
			m[s[i]]++;

		if (m_cnt < m[s[i]]) {
			m_cnt = m[s[i]];
			res = s[i];
		}
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (m_cnt == it->second && res != it->first)
			res = '?';
	}
	cout << res;
}