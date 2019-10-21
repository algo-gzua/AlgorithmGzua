#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

using namespace std;

bool visited[10010];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 10010; i++) {
		int sum = i;
		int num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum >= 10000)
			continue;
		visited[sum] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (visited[i] != true) {
			cout << i << "\n";
		}
	}
}