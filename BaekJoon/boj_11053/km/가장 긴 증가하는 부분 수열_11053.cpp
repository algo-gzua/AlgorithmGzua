#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	vector<int> v;

	cin >> N;

	v.push_back(0);
	for (int i = 0; i < N; ++i)
	{
		int input;

		cin >> input;

		if (input > *(v.end() - 1))
		{
			v.push_back(input);
		}
		else
		{
			auto iter = lower_bound(v.begin(), v.end(), input);
			*iter = input;
		}
	}

	cout << v.size() - 1;

	return 0;
}