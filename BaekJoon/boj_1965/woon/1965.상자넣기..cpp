#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> v;

	cin >> n;

	v.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		int input;

		cin >> input;

		if (input > v.back())
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