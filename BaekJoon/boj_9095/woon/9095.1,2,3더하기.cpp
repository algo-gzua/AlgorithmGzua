#include <iostream>
using namespace std;

int main() {

	int dp[12];

	int n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	// 점화식 +1 씩 증가하는게 아님;;
	// 전부 합친수

	
	for (int i = 3; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	

	int a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		cout << dp[a-1] << endl;
	}



	return 0;
}