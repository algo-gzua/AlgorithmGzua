#include <iostream>
#include <string>

using namespace std;

char board[301][301];
int direct[8][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
int N;
bool flag;

void search_zero(int a, int b)
{
	int count = 0;
	for (int k = 0; k < 8; ++k)
	{
		int new_a = a + direct[k][0];
		int new_b = b + direct[k][1];

		if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N)
		{
			if (board[new_a][new_b] == '*' && !flag)
			{
				return;
			}

			if (flag)
			{
				if (board[new_a][new_b] == '*')
				{
					count++;
				}
			}
		}
	}

	board[a][b] = count + '0';

	if (count != 0)
	{
		return;
	}

	flag = true;

	for (int k = 0; k < 8; ++k)
	{
		int new_a = a + direct[k][0];
		int new_b = b + direct[k][1];

		if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N && board[new_a][new_b] == '.')
		{
			search_zero(new_a, new_b);
		}
	}
}

int main(void)
{
	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; ++t)
	{
		int result = 0;

		cin >> N;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				cin >> board[i][j];
			}
		}

		// 0 찾기
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (board[i][j] == '.')
				{
					flag = false;

					search_zero(i, j);

					if (board[i][j] != '.')
					{
						result++;
					}
				}
			}
		}

		// . 열기
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				int count = 0;

				if (board[i][j] == '.')
				{
					result++;
				}
			}
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}