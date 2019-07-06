#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int i;
	int j;
	int distance;
};

int N, M;
char board[51][51];
bool visit[51][51];
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(int I, int J)
{
	queue<Node> q;
	fill(&visit[0][0], &visit[0][0] + sizeof(visit), false);

	visit[I][J] = true;
	q.push({I, J, 0});

	int result = 0;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int new_i = node.i + direction[i][0];
			int new_j = node.j + direction[i][1];

			if (new_i < N && new_i >= 0 && new_j < M && new_j >= 0 && !visit[new_i][new_j] && board[new_i][new_j] == 'L')
			{
				q.push({ new_i, new_j, node.distance + 1 });
				visit[new_i][new_j] = true;
			}
		}

		if (q.empty())
		{
			result = node.distance;
		}
	}

	return result;
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char x;

			cin >> x;

			board[i][j] = x;
		}
	}

	int result = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 'L')
			{
				result = max(result, bfs(i, j));
			}
		}
	}

	cout << result;

	return 0;
}