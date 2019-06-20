#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool is_prime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	int size = (int)sqrt(num);
	for (int i = 2; i <= size; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		int number;
		scanf("%d", &number);

		if (is_prime(number))
		{
			result++;
		}
	}

	printf("%d", result);

	return 0;
}