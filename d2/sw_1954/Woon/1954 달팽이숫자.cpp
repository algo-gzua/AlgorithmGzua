#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct node {
	int y;
	int x;
};

void print(int snail[][11],int n) {

	int x, y;

	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			cout << snail[x][y] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int T, test_case,num=1;
	int snail[11][11] = { 0, };

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		int n;
		int size;
		int k = 1;
		int dir = 1;
		int x = 0, y = -1;

		cin >> n;	
		size = n;

		while(size>=0){
			//달팽이 만들기 , 시작점 설정
			for (int i = 0; i < size; i++) {
				y = y + dir;
				snail[x][y] = k;
				k++;
			}
			size--;

			for (int i = 0; i < size; i++) {
				x = x + dir;
				snail[x][y] = k;
				k++;
			}
			dir = dir * (-1);
		}
		//출력
			cout << "#" << num++ << endl;
			print(snail, n);
	}
	return 0;
}