#include<iostream>
typedef long long int ll;

using namespace std;

ll arr[10];

void jari(ll n, ll t) {
	while (n > 0) {
		arr[n % 10] += t;
		n = n / 10;
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		fill(arr, arr + 10, 0);
		ll A, B;
		ll ttt = 1;
		scanf("%lld %lld", &A, &B);

		while (A <= B) {
			while (A % 10 != 0 && A <= B) {
				jari(A, ttt);
				A++;
			}

			if (A > B) break;
			while (B % 10 != 9 && A <= B) {
				jari(B, ttt);
				B--;
			}

			if (A > B) break;

			ll cnt = (B / 10 - A / 10) + 1;
			for (int i = 0; i <= 9; i++) {
				arr[i] += cnt*ttt;
			}

			ttt *= 10;
			A /= 10; B /= 10;
		}
		ll sum = 0;

		for (int i = 0; i <= 9; i++) {
			sum += arr[i] * i;
		}

		printf("#%d %lld\n", t, sum);
	}
}