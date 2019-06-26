#include<iostream>
#include<algorithm>
#define SIZE 100010
using namespace std;

typedef long long int ll;

typedef struct data {
	int start;
	int end;

	bool operator < (const data &d) {
		if (end == d.end) {
			return start < d.start;
		}
		return end < d.end;
	}
}Data;

Data arr[SIZE];

int main(void) {
	int N; scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}

	sort(arr, arr + N);

	ll cnt = 0;
	ll start = arr[0].start;
	ll end = arr[0].end;

	for (int i = 1; i < N; i++) {
		if (arr[i].start >= end) {
			cnt++;
			end = arr[i].end;
		}
	}

	printf("%lld", cnt+1);
}