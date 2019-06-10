#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
	int y;
	int x;
};

int main(void)
{
	int board[16][16];
	bool visit[16][16] = { false, };
	int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	for (int t = 1; t <= 10; ++t)
	{
		int c;
		int start_x = 0, start_y = 0;
		int end_x = 0, end_y = 0;

		int result = 0;
		fill(&visit[0][0], &visit[15][15], false);

		cin >> c;
		for (int i = 0; i < 16; ++i)
		{
			string s;
			cin >> s;
			for (int j = 0; j < 16; ++j)
			{
				board[i][j] = s[j] - '0';

				if (board[i][j] == 2)
				{
					start_x = j;
					start_y = i;
				}
				else if (board[i][j] == 3)
				{
					end_x = j;
					end_y = i;
				}
			}
		}

		// 시작점에서 끝점까지 갈 dfs
		stack<Node> st;

		visit[start_y][start_x] = true;
		st.push({ start_y, start_x });

		while (!st.empty())
		{
			Node n = st.top();
			st.pop();

			if (n.x == end_x && n.y == end_y)
			{
				result = 1;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int x = n.x + direction[i][0];
				int y = n.y + direction[i][1];

				// 맵 밖으로 안나간다면
				if (x >= 0 && x < 16 && y >= 0 && y < 16)
				{
					if (board[y][x] != 1 && !visit[y][x])
					{
						visit[y][x] = true;
						st.push({ y, x });
					}
				}
			}
		}

		cout << "#" << c << " " << result << "\n";
	}

	return 0;
}