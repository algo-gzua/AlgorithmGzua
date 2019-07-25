#include <iostream>
#include <algorithm>

using namespace std;

int multi[101];
int one[101];

int main(void)
{
	int N, M;

	cin >> N >> M;

	for (int m = 0; m < M; ++m)
	{
		cin >> multi[m] >> one[m];
	}

	sort(multi, multi + M);
	sort(one, one + M);

	int result = 0;
	
	if (multi[0] < 6 * one[0])
	{
		result += (N / 6) * multi[0];
		N -= (N / 6) * 6;

		if (multi[0] >= N * one[0])
		{
			result += N * one[0];
		}
		else
		{
			result += multi[0];
		}
	}
	else
	{
		result += N * one[0];
	}
	
	cout << result;

	return 0;
}