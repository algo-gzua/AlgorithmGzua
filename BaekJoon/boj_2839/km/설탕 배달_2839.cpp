#include <iostream>
#include <algorithm>
#include <string>
#define INF 2147483647

using namespace std;

int check(int num)
{
	if (num % 5 == 0)
	{
		return num / 5;
	}
	
	int result = INF;
	int cycle = 0;
	while (num > 0)
	{
		if (num % 3 == 0)
		{
			int temp_result = num / 3;
			result = min(temp_result + cycle, result);
		}

		num -= 5;
		cycle++;
	}

	if (result == INF)
	{
		return -1;
	}

	return result;
}

int main(void)
{
	int N;

	cin >> N;

	cout << check(N) << "\n";

	return 0;
}