#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int jump[10001];

int main(void)
{
	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; ++t)
	{
		int N;

		cin >> N;

		for (int i = 1; i <= N; ++i)
		{
			cin >> jump[i];
		}

		sort(&jump[1], &jump[N + 1]);

		stack<int> st;
		queue<int> q;
		vector<int> v;

		v.push_back(jump[1]);

		for (int i = 2; i <= N; ++i)
		{
			if ((i & 1) == 0)
			{
				q.push(jump[i]);
			}
			else
			{
				st.push(jump[i]);
			}
		}

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			v.push_back(node);
		}

		while (!st.empty())
		{
			auto node = st.top();
			st.pop();

			v.push_back(node);
		}

		int result = abs(v[N - 1] - v[0]);

		for (int i = 0; i < N - 1; ++i)
		{
			result = max(result, abs(v[i] - v[i + 1]));
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}