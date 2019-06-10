#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int square(int a, int b) {
	int result = 0;

	result = pow(a, b);
	return result;
}



int main() {

	int tc;

	for (tc = 0; tc < 10; tc++) {

		int a, b;

		cin >> a >> b;
	
		
		cout << "#" << tc+1 <<" "<< square(a, b);


	}
	return 0;
}