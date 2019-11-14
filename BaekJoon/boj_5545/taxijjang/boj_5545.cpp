#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> b_kcal;

bool cmp(int a, int b) {
	return a > b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	//A 도우 가격 , B 토핑 가격 , C 도우 열량
	int A, B, C; cin >> A >> B >> C;


	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		b_kcal.push_back(n);
	}

	sort(b_kcal.begin(), b_kcal.end(), cmp);
	
	int total_kcal = C;
	int cost = A;
	int res = 0;
	for (int topping = 0; topping < N; topping++) {
		total_kcal += b_kcal[topping];
		cost += B;
		int tmp_res = total_kcal / cost;
		res = res < tmp_res ? tmp_res : res;
	}

	getchar();
}