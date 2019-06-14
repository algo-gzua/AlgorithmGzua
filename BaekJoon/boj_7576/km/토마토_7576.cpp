#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
	int turn;
};

int box[1001][1001];
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void)
{
	int x, y;

	cin >> x >> y;

	queue<Point> q;

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				q.push({i, j, 0});
			}
		}
	}

	int result = 0;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int new_x = node.x + direction[i][1];
			int new_y = node.y + direction[i][0];

			if (new_x >= 0 && new_x < x && new_y >= 0 && new_y < y)
			{
				if (box[new_y][new_x] == 0)
				{
					box[new_y][new_x] = 1;
					q.push({ new_y, new_x, node.turn + 1 });
				}
			}
		}

		if (q.empty())
		{
			result = node.turn;
		}
	}

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			if (box[i][j] == 0)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << result << "\n";

	return 0;
}