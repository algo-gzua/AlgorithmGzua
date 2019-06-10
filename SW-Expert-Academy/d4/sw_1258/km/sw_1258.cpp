#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int row;
	int col;
	int multi;
};

int board[101][101];
bool visit[101][101];
vector<Node> v;

bool compare(Node a, Node b)
{
	if (a.multi < b.multi)
	{
		return true;
	}
	else if (a.multi == b.multi)
	{
		return a.col < b.col;
	}

	return false;
}

void check_size(int a, int b)
{
	Node n;

	int row = 0;
	int temp = b;
	// 가로 체크
	while (board[a][temp] != 0)
	{
		temp++;
		row++;
	}

	int col = 0;
	temp = a;
	// 세로 체크
	while (board[temp][b] != 0)
	{
		temp++;
		col++;
	}

	// 사각형 visit check
	for (int i = a; i < a + col; ++i)
	{
		for (int j = b; j < b + row; ++j)
		{
			visit[i][j] = true;
		}
	}

	n.row = row;
	n.col = col;
	n.multi = row * col;

	v.push_back(n);
}

int main(void)
{
	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; ++t)
	{
		int n;

		cin >> n;

		fill(&visit[0][0], &visit[n][n], false);
		fill(&board[0][0], &board[n][n], 0);
		vector<Node>().swap(v);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] != 0 && !visit[i][j])
				{
					check_size(i, j);
				}
			}
		}

		sort(v.begin(), v.end(), compare);

		cout << "#" << t << " " << v.size() << " ";
		for (auto iter = v.begin(); iter != v.end(); ++iter)
		{
			cout << iter->col << " " << iter->row << " ";
		}
		cout << "\n";
	}

	return 0;
}