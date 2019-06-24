#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[12];

int main(void)
{
	int T;

	cin >> T;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int t = 0; t < T; ++t)
	{
		int n;

		cin >> n;

		cout << arr[n] << "\n";
	}

	return 0;
}