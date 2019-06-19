#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

struct Node
{
	int number;
	int cost;
};

struct compare
{
	bool operator()(Node a, Node b)
	{
		return a.cost > b.cost;
	}
};

vector<Node> v[1001];
int dist[1001];

int dijkstra(int start, int destination)
{
	fill(&dist[0], &dist[1001], INF);

	dist[start] = 0;
	priority_queue<Node, vector<Node>, compare> pq;

	pq.push({ start, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		for (auto next : v[curr.number])
		{
			if (next.cost + dist[curr.number] < dist[next.number])
			{
				dist[next.number] = next.cost + dist[curr.number];
				pq.push({ next.number, dist[next.number] });
			}
		}
	}

	return dist[destination];
}

int main(void)
{
	int N, M, X;

	scanf("%d %d %d", &N, &M, &X);

	for (int m = 0; m < M; ++m)
	{
		int start, end, cost;

		scanf("%d %d %d", &start, &end, &cost);

		v[start].push_back({ end, cost });
	}

	int result = 0;
	for (int n = 1; n <= N; ++n)
	{
		int dijkstra_result = 0;

		dijkstra_result += dijkstra(n, X);
		dijkstra_result += dijkstra(X, n);

		result = max(result, dijkstra_result);
	}

	printf("%d\n", result);

	return 0;
}