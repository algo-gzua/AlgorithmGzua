#include <iostream>
#include <algorithm>
using namespace std;

//dp의 핵심은 해를 배열에 저장하고 이를 '이용'하는것이다.

int R, G, B;
void dp(int house[][3], int n) {
	int i,j;

	for (i = 1; i <= n-1; i++) {
		house[i][0] = house[i][0] + min(house[i - 1][1], house[i - 1][2]);
		house[i][1] = house[i][1] + min(house[i - 1][0], house[i - 1][2]);
		house[i][2] = house[i][2] + min(house[i - 1][0], house[i - 1][1]);
		
		R = house[i][0];
		G = house[i][1];
		B = house[i][2];
	}
}

void print(int house[][3],int n) {
	cout << min(min(R,G),B);
}

int main() {

	int house[1000][3];
	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}

	dp(house,n);
	print(house,n);


	return 0;
}