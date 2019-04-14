#include<iostream>
#include<string>
#include<vector>
using namespace std;


int Judge(vector<int>& v,int k) {
	int m;

	for (int i = 1; i <= k; i++) {
		cin >> m;
		v[m-1] = 1;
	}
	return 0;
}
int search(vector<int>& v, vector<int>& c) {
	int len = v.size();
	int i;

	for (i = 0; i < len; i++) {
		if (v[i] == 0) {
			c.push_back(i + 1);
		}
	}
	return 0;
}


int main() {

	int t,tc;
	vector<int> v;
	vector<int> c;
	vector<int> vclear;
	vector<int> cclear;

	cin >> t;
	for (tc = 0; tc < t; tc++) {
		//수강생 수(n) , 제출 한 사람수(k)
		int n, k;
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++) {
			v.push_back(0);
		}

		Judge(v, k);
		search(v, c);
		
		cout << "#" << tc+1 << " ";
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << " ";
		}
		cout << endl;

		v.swap(vclear);
		vclear.clear();
		v.clear();

		c.swap(cclear);
		cclear.clear();
		c.clear();
	}
	return 0;
}