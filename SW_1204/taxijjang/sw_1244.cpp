#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;
int result = 0;
void dfs(string num, int n_size, int change, int cnt,int here) {
	if (cnt == change) { result = max(result, stoi(num)); return; }
	else {
		for (int i = here; i < n_size - 1; i++) {
			for (int j = i + 1; j < n_size; j++) {
				if (num[i] <= num[j]) {
					char tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
					dfs(num, n_size, change, cnt + 1,here);
					tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
				}
			}
		}
	}
}

int main(void) {
	int C; scanf("%d", &C);

	for (int c = 1; c <= C; c++) {
		char NUM[10]; scanf("%s", NUM);
		string num;	num = NUM;
		
		int n_size = num.size();

		int change; scanf("%d", &change);
		result = 0;
		dfs(num, n_size, change, 0,0);
		printf("#%d %d\n",c,result);
		
	}
}