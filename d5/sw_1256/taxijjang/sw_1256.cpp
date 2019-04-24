#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);

		string word;
		cin >> word;

		int w_size = word.size();

		if (w_size < n) {
			printf("#%d none\n",t);
		}
		else {
			string arr[501];

			for (int i = 1; i <= w_size; i++) {
				arr[i] = word.substr(i-1,w_size );
			}

			sort(arr, arr + w_size+1);

			cout << "#" << t << " " << arr[n] << "\n";
		}
		
	}
}