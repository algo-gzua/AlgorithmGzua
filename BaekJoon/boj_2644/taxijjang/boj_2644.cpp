#include<iostream>
#include <vector>
#include<queue>

#define SIZE 110

using namespace std;

vector<int> arr[SIZE];
bool visited[SIZE];

int main(void) {
	int N; scanf("%d", &N);
	int m1, m2; scanf("%d %d", &m1, &m2);

	int m; scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	queue<pair<int,int>> q;

	q.push({ m1,0 });
	visited[m1] = true;

	int cnt = -1;
	while (!q.empty()) {
		pair<int,int> man = q.front();
		q.pop();

		for (auto next : arr[man.first]) {
			if (visited[next] != true) {
				q.push({ next,man.second +1});
				visited[next] = true;
				if (next == m2) cnt = man.second + 1;
			}
		}
	}

	printf("%d\n", cnt);
	
}