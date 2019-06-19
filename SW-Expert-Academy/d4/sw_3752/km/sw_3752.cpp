#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int input[101];
bool score[10001];

int main(void)
{
	int T;

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;

		cin >> N;

		fill(&input[0], &input[100], 0);
		fill(&score[0], &score[10000], false);

		for (int i = 0; i < N; ++i)
		{
			cin >> input[i];
		}

		score[0] = true;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 10000; j >= 0; --j)
			{
				if (score[j])
				{
					score[j + input[i]] = true;
				}
			}
		}

		int result = 0;

		for (int i = 0; i <= 10000; ++i)
		{
			if (score[i])
			{
				result++;
			}
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}