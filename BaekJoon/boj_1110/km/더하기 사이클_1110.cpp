#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int N;

	cin >> N;

	int result = 0;

	int curr = N;

	do
	{
		if (curr < 10)
		{
			curr = curr + curr * 10;
		}
		else
		{
			int one = curr / 10;
			int two = curr % 10;
			curr = two * 10 + (one + two) % 10;
		}
		result++;
	} while (N != curr);

	cout << result << "\n";

	return 0;
}