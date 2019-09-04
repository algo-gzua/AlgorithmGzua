#include <string>
#include<iostream>
using namespace std;

bool check;
int res[3];

int calc(int num, char gi) {
	int n; n = num < 0 ? num*-1 : num;
	if (gi == 'S')
		return num;
	else if (gi == 'D')
		return num*n;
	else
		return num*n*n;
}
int solution(string dartResult) {
	string d = dartResult;
	int d_size = dartResult.size();
	int n_i = 0, g_i = 0;
	for (int i = 0; i < d_size; i++) {
		if (d[i]>= '0' && d[i] <= '9') {
			if (d[i] == '1') {
				if (d[i + 1] == '0') {
					res[n_i] = 10;
					i++;
					continue;
				}
			}
			res[n_i] = d[i] - '0';
		}
		else if (d[i] >= 'A' && d[i] <= 'Z') {
			res[n_i] = calc(res[n_i], d[i]);
			n_i++;
		}
		else if (d[i] == '*' || d[i] == '#') {
			if (d[i] == '*') {
				for(int j = 1 ; j<=2 ; j++)
					res[n_i - j] *= 2;
			}
			else if (d[i] == '#')
				res[n_i - 1] *= -1;
		}
	}

	int answer=0;
	for (int i = 0; i < 3; i++) {
		answer += res[i];
	}
	return answer;
}

int main(void) {
	string s; cin >> s;

	cout << solution(s);
}