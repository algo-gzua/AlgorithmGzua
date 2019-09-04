#include <string>
#include <vector>
#include<iostream>

using namespace std;

char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string num_append(int num, int n) {
	string s = "";

	while (num / n != 0) {
		s = c[num % n] + s;
		num = num / n;
	}
	s = c[num % n] + s;
	return s;
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	string filter = "";
	for (int i = 0; i <= t*m; i++) {
		filter = filter + num_append(i, n);
	}

	for (int i = p - 1, cnt = 1; cnt <= t; i = i + m, cnt++) {
		answer += filter[i];
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);

	int n, t, m, p;
	cin >> n >> t >> m >> p;

	cout << solution(n, t, m, p);
}