#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
	int index;
	int frequent;
};

bool compare(pair<int, Node> v1, pair<int, Node> v2)
{
	if (v1.second.frequent > v2.second.frequent)
	{
		return true;
	}
	else if (v1.second.frequent == v2.second.frequent)
	{
		if (v1.second.index < v2.second.index)
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	map<int, Node> m;
	
	int N, C;

	cin >> N >> C;

	for (int i = 0; i < N; ++i)
	{
		int x;

		cin >> x;

		if (m.count(x) <= 0)
		{
			m.insert(pair<int, Node>(x, { i, 1 }));
		}
		else
		{
			m[x].frequent++;
		}
	}

	vector<pair<int, Node>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), compare);

	int size = v.size();

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < v[i].second.frequent; ++j)
		{
			printf("%d ", v[i].first);
		}
	}

	return 0;
}