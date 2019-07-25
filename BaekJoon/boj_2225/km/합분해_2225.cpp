#include <iostream>
#include <algorithm>

using namespace std;

int d[201][201];

int main(void)
{
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= 200; ++i)
	{
		d[i][1] = 1;
	}

	for (int i = 2; i <= 200; ++i)
	{
		d[1][i] = i;
	}

	for (int i = 2; i <= 200; ++i)
	{
		for (int j = 2; j <= 200; ++j)
		{
			d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 1000000000;
		}
	}

	cout << d[N][K];

	return 0;
}