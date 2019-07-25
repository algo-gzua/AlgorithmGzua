#include<iostream>
#define SIZE 101

typedef long long int ll;

ll arr[SIZE] = { 0,1,1,1,2 };
int main(void){
	int T; scanf("%d", &T);

	for (int i = 5; i < SIZE; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	for (int t = 1; t <= T; t++) {
		ll n; scanf("%lld", &n);
		printf("%lld\n", arr[n]);
	}
}