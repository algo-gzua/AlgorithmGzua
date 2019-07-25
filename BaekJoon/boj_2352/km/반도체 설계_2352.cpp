#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[40001];

int main() 
{
	ios::sync_with_stdio(false);

	int N;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}

	v.push_back(0);

	for (int i = 0; i < N; ++i) 
	{
		if (*(v.end() - 1) < arr[i]) 
		{
			v.push_back(arr[i]);
		}
		else
		{
			int left = 0;
			int right = v.size();

			while (left < right)
			{
				int mid = (left + right) / 2;

				if (v[mid] < arr[i]) 
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}

			v[right] = arr[i];
		}
	}

	cout << v.size() - 1;

	return 0;
}