#include<iostream>
#include<string>
using namespace std;


// 회문만들기
int palindrome(string word, int t) {
	int check = 0;
	for(int i=0; i < word.length() / 2; i++) {
		if (word[i] == word[word.length() - i - 1]) {
			check = 1;
		}
		else {
			check = 0;
		}
	}
	return check;
}

int main() {

	int t;
	string word;
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		//테스트 케이스에 해당하는 단어 입력받기
		cin >> word;
		//output
		cout << "#" << i+1 << " " << palindrome(word,t) << endl;
	}
	return 0;
}