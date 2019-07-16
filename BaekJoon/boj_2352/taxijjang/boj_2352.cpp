#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
int main(void) {
	int N; scanf("%d", &N);

	arr.push_back(-1);
	for (int i = 0; i < N; i++) {
		int num; scanf("%d", &num);
		auto it = arr.end();
		if (num > *(it - 1))
			arr.push_back(num);
		else {
			auto iter = lower_bound(arr.begin(), arr.end(), num);
			*iter = num;
		}
	}

	printf("%d", arr.size() - 1);

	return 0;
}