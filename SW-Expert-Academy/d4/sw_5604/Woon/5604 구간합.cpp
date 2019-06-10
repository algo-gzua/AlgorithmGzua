#include<iostream>
#include<vector>
using namespace std;

int main() {

	int tc, t;

	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		
		int a, b, i;
		vector<int> v;


		scanf("%d %d", &a, &b);
		// 배열에 값 넣기
		for (i = a; i <= b; i++) {
			v.push_back(i);
		}

		int length = v.size();
		int number = 0;

		for (i = 0; i < length; i++) {
			while (v[i] != 0) {
				number = number + (v[i] % 10);
				v[i] = v[i] / 10;
			}
		}

		printf("#%d %d\n",tc+1,number);
	}
	return 0;
}