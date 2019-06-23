#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Room
{
	int start;
	int end;
};

Room rooms[100001];

bool compare(Room A, Room B)
{
	if (A.end == B.end)
	{
		return A.start < B.start;
	}

	return A.end < B.end;
}

int main(void)
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int a, b;

		cin >> a >> b;

		rooms[i] = { a, b };
	}

	sort(rooms + 1, rooms + N + 1, compare);

	Room curr = rooms[1];
	int result = 1;

	for (int i = 2; i <= N; ++i)
	{
		if (curr.end <= rooms[i].start)
		{
			curr = rooms[i];
			result++;
		}
	}

	cout << result;

	return 0;
}