#include <iostream>
#include <algorithm>
using namespace std;

int score[100];
bool visited[10000];

int main() {

	int i,j,n;
	int a;
	int t, tc;
	
	cin >> t;
	for (tc = 0; tc < t; tc++) {
		
		cin >> n;

		fill(&score[0], &score[100], 0);
		fill(&visited[0], &visited[10000], false);

		int sum = 0;
		score[0] = 0;
		visited[0] = true;

		for (i = 0; i < n; i++) {
			cin >> a;
			sum = sum + a;

			// 뒤에서 부터도 생각하자
			for (j = sum; j >= 0; j--) {
				if (visited[j]) {
					score[j + a] = j + a;
					visited[j + a] = true;
				}
			}
		}

		int count = 0;
		for (i = 0; i <= sum; i++) {
			if (visited[i]) {
				count = count + 1;
			}
		}

		cout << "#" << tc + 1 <<" "<< count << endl;

	}
	return 0;
}