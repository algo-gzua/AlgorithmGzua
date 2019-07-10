#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE 1001
#define INF 1999999999
using namespace std;


typedef struct Data {
	int cnt = 0;
	int loc = 0;
	int num = 0;


}Data;

/*
나온 숫자의 갯수가 같을 경우
먼저 나온 숫자대로 정렬을 하였고
나머지는 숫자의 갯수대로 정렬
*/
struct cmp {
	bool operator()(Data d1, Data d2) {
		if (d1.cnt == d2.cnt) {
			return d1.loc > d2.loc;
		}
		return d1.cnt < d2.cnt;
	}
};

/*
정렬기준을 숫자가 같으면
먼저 나온 숫자대로 정렬을 함
*/
typedef struct In {
	int num = 0;
	int loc = 0;

	bool operator < (In i) {
		if (num == i.num) {
			return loc < i.loc;
		}
		return num < i.num;
	}
}In;
In arr[SIZE];

int main(void) {
	int N, C; scanf("%d %d", &N, &C);

	priority_queue<Data, vector<Data>, cmp> pq;

	int index = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i].num);
		arr[i].loc = index++;
	}

	sort(arr, arr + N);
	bool judge = false;
	int num = arr[0].num;
	int cnt = 1;
	int n_first = arr[0].loc;
	for (int i = 1; i < N; i++) {
		if (num == arr[i].num) {
			cnt++;
			n_first = n_first > arr[i].loc ? arr[i].loc : n_first;
			judge = true;
		}
		else if (num != arr[i].num) {
			Data dd;
			dd.cnt = cnt; dd.loc = n_first; dd.num = num;
			pq.push(dd);
			num = arr[i].num;
			cnt = 1;
			judge = false;
			n_first = INF;
			n_first = n_first > arr[i].loc ? arr[i].loc : n_first;

		}
	}

	if (judge = true) {
		Data dd;
		dd.cnt = cnt; dd.loc = n_first; dd.num = num;
		pq.push(dd);
	}

	int pq_size = pq.size();
	for (int i = 0; i < pq_size; i++) {
		int cnt = pq.top().cnt;
		for (int j = 0; j < cnt; j++) {
			printf("%d ", pq.top().num);
		}
		pq.pop();
	}
	return 0;
}