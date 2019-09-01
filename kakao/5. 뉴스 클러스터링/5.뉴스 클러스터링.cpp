#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
vector<string> v1;
bool check[1000];

void make(string str1, string str2) {
	int size1 = str1.size();
	int size2 = str2.size();

	string s = "";
	string s1 = "";
	int i = 0;
	int len = 0;
	while (true) {
		//아스키코드
		if (i == size1) {
			break;
		}
		if (65 <= str1[i] && str1[i] <= 90 || 97 <= str1[i] && str1[i] <= 122) {
			if (65 <= str1[i] && str1[i] <= 90) {
				str1[i] = str1[i] + 32;
			}
			s = s + str1[i];
			len = s.length();

			if (len == 2) {
				v.push_back(s);
				s = "";
				len = 0;
			}
			else {
				i++;
			}
		}
		else {
			i++;
			s = "";
		}
	}

	i = 0;
	s = "";
	while (true) {
		//아스키코드
		if (i == size2) {
			break;
		}
		if (65 <= str2[i] && str2[i] <= 90 || 97 <= str2[i] && str2[i] <= 122) {
			//소문자로 바꾸는 과정
			if (65 <= str2[i] && str2[i] <= 90) {
				str2[i] = str2[i] + 32;
			}
			s = s + str2[i];
			len = s.length();

			if (len == 2) {
				v1.push_back(s);
				s = "";
				len = 0;
			}
			else {
				i++;
			}
		}
		else {
			i++;
			s = "";
		}
	}
}

int inun(int size1, int size2) {

	vector<string> a;
	vector<string> b;
	int in = 0, un = 0;
		
	//큰거는 고정 작은걸 큰거에 비교하기
	// v > v1
	if (size1 >= size2) {
		for (int i = 0; i < size1; i++) {
			b.push_back(v[i]);
			un++;
			for (int j = 0; j < size2; j++) {

				//교집합
				if(check[j] == true){
					continue;
				}
				else {
					if (v1[i] == v[j]) {
						a.push_back(v1[j]);
						in++;
						check[i] = true;
						break;
					}
					else {
						//합집합

						if (v1[i][0] >= v[j][0]) {
							if (j == size1 - 1) {
								b.push_back(v1[j]);
								un++;
							}
							continue;
						}
						else {
							b.push_back(v1[j]);
							un++;
							break;
						}
					}
				}
			}
		}
	}

	// v < v1
	else {
		for (int i = 0; i < size2; i++) {
			b.push_back(v1[i]);
			un++;
			for (int j = 0; j < size1; j++) {

				if (check[j] == true) {
					continue;
				}
				if (v1[i] == v[j]) {
					a.push_back(v[j]);
					in++;
					check[i] = true;
					break;
				}
				else {
					if (v[i][0] >= v1[j][0]) {
						if (j == size1 - 1) {
							b.push_back(v[j]);
							un++;
						}
						continue;
					}
					else {
						b.push_back(v[j]);
						un++;
						break;
					}
				}
			}
		}
	}

	int sim;
	// 유사도 = (교집합 * 65536 / 합집합) -> 유사도 = (65536/ 합집합) * 교집합
	sim = (65536 / un) * in;

	return sim;
}

int solution(string str1, string str2) {
	int answer = 0;

	//자카드 유사도 만들기

	make(str1, str2);
	int size1 = v.size();
	int size2 = v1.size();

	if (size1 == 0 && size2 == 0) {
		//un, in = 1;
		return 65536;
	}

	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());

	//교집합, 합집합 구하기
	// int 결과값 = 유사도 * 65536
	answer = inun(size1, size2);
	return answer;
}

int main() {

	//string str1 = "FRANCE";
	//string str2 = "french";

	//string str1 = "handshake";
	//string str2 = "shake hands";

	//string str1 = "aa1+aa2";
	//string str2 = "AAAA12";

	//string str1 = "E=M*C^2";
	//string str2 = "e=m*c^2";

	string str1 = "ssAssA";
	string str2 = "AsasSa";
	cout << solution(str1, str2);
	return 0;
}