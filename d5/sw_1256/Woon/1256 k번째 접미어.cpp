#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int i,k,tc,t;
	string s;

	vector<string> v;
	vector<string>::iterator iter = v.begin();
	
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &k);

		cin >> s;
 		int length = s.size();

		// ���� �ȿ� string�� ���̸�ŭ �־��ְ� �Ǿտ� ����
		// erase�� �ش� �ε����� ����� �����͸� �����ڸ��� ��ܿ�
		for (i = 0; i < length; i++) {
			v.push_back(s);
			s.erase(0, 1);
		}

		sort(v.begin(), v.end());


		cout << "#"<<tc+1<<" "<< v[k - 1] << endl;
	}
	return 0;
}