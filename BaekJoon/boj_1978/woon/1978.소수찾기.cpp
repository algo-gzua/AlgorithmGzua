#include <iostream>
#include <math.h>

using namespace std;

int main() {

	bool visited[1001] = { false, };
	
	visited[0] = visited[1] = true;
	for (int i = 2; i <= sqrt(1000); i++) {
		if (visited[i]) {
			continue;
		}
		for (int j = i+i; j <= 1000; j=j+i) {
				visited[j] = true;
		}
	}

	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (!visited[a]) {
			count = count + 1;
		}
	}



	return 0;
}