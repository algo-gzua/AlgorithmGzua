#include<iostream>
#include<string>
using namespace std;


// ȸ�������
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
		//�׽�Ʈ ���̽��� �ش��ϴ� �ܾ� �Է¹ޱ�
		cin >> word;
		//output
		cout << "#" << i+1 << " " << palindrome(word,t) << endl;
	}
	return 0;
}