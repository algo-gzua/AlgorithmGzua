#include <iostream>
#include <algorithm>
#include <string>
#define INF 1000000001

using namespace std;

int tree[300001];

int main(void)
{
	int N, M;

	scanf("%d %d", &N, &M);

	int size = 1;
	while (size < N)
	{
		size <<= 1;
	}

	fill(&tree[0], &tree[300000], INF);

	// init leaf node
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &tree[size + i]);
	}

	// init parent node
	int index = size;
	while (index > 1)
	{
		for (int i = index; i < index + index; i += 2)
		{
			tree[i / 2] = min(tree[i], tree[i + 1]);
		}

		index /= 2;
	}


	for (int j = 1; j <= M; ++j)
	{
		int left, right;

		scanf("%d %d", &left, &right);
		// cin >> left >> right;

		// 1∫Œ≈Õ Ω√¿€¿Ã∂Ûº≠ 1 ª©¡‹
		left += size - 1;
		right += size - 1;

		int result = INF;

		while (left < right)
		{
			if (left % 2 == 1)
			{
				result = min(result, tree[left]);
				left++;
			}

			if (right % 2 == 0)
			{
				result = min(result, tree[right]);
				right--;
			}

			left /= 2;
			right /= 2;
		}

		if (left == right)
		{
			result = min(result, tree[left]);
		}
		
		printf("%d\n", result);
		// cout << result << "\n";
	}

	return 0;
}