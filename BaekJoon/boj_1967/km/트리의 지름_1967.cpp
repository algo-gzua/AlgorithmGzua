#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int destination;
	int distance;
};

struct Point
{
	int position;
	int sum;
};

vector<Node> v[10001];
bool visit[10001];

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v[i].size() == 1)
		{
			queue<Point> q;
			fill(visit, visit + 10001, false);

			q.push({ v[i][0].destination, v[i][0].distance });
			visit[i] = true;
			visit[v[i][0].destination] = true;

			while (!q.empty())
			{
				auto node = q.front();
				q.pop();

				result = max(result, node.sum);

				for (Node n : v[node.position])
				{
					if (!visit[n.destination])
					{
						q.push({ n.destination, node.sum + n.distance });
						visit[n.destination] = true;
					}
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}