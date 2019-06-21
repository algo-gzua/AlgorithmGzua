#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10001];

int main(void)
{
	int T;

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;

		cin >> N >> K;

		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		sort(arr, arr + N);

		double result = 0.0;

		for (int i = N - K; i < N; ++i)
		{
			result += arr[i];
			result /= 2;
		}

		printf("#%d %lf\n", t, result);
	}
	return 0;
}