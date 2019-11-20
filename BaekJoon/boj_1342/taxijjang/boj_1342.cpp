#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int s_size = s.size();
	vector<char> combi;

	for (int i = 0; i < s_size; i++) {
		combi.push_back(s[i]);
	}

	sort(combi.begin(), combi.end());

	int res = 0;
	do {
		bool toggle = true;

		for (int i = 0; i < s_size; i++) {
			char here = combi[i];
			if (i == 0 ) {
				if (here == combi[i + 1]) {
					toggle = false;
					break;
				}
			}
			else if (i == s_size - 1) {
				if (here == combi[i - 1]) {
					toggle = false;
					break;
				}
			}
			else {
				if (here == combi[i - 1] || here == combi[i + 1]) {
					toggle = false;
					break;
				}
			}
		}
		if (toggle) {
			res++;
		}

	} while (next_permutation(combi.begin(),combi.end()));

	cout << res;
}