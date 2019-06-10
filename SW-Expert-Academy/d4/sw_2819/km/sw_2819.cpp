#include <iostream>
#include <set>
#include <string>

using namespace std;

int board[4][4];
set<string> s;
int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int count, string str)
{
	if (count == 7)
	{
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int new_x = x + direct[i][0];
		int new_y = y + direct[i][1];

		if (new_x < 4 && new_x >= 0 && new_y < 4 && new_y >= 0)
		{
			dfs(new_x, new_y, count + 1, str + to_string(board[new_x][new_y]));
		}
	}
}

int main(void)
{
	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; ++t)
	{
		set<string>().swap(s);

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				// ½ÃÀÛÁ¡
				dfs(i, j, 1, to_string(board[i][j]));
			}
		}

		printf("#%d %d\n", t, s.size());
	}

	return 0;
}