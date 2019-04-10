#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		int check = 9999999999;
		for (int n = 0; n < N; n++) {
			string s;
			cin >> s;

			int index;
			bool judge = false;
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] == '1') {
					index = i;
					judge = true;;
					break;
				}
			}
			
			if (judge) {
				index -= 55;
				int code[8] = { 0 };
				for (int i = 0; i < 8; i++) {
					string cryto = s.substr((7 * i) + index, 7);

					if (cryto == "0001101") {//0
						code[i] = 0;
					}
					else if (cryto == "0011001") {//1
						code[i] = 1;
					}
					else if (cryto == "0010011") {//2
						code[i] = 2;
					}
					else if (cryto == "0111101") {//3
						code[i] = 3;
					}
					else if (cryto == "0100011"){//4
						code[i] = 4;
					}
					else if (cryto == "0110001") {//5
						code[i] = 5;
					}
					else if (cryto == "0101111") {//6
						code[i] = 6;
					}
					else if (cryto == "0111011") {//7
						code[i] = 7;
					}
					else if (cryto == "0110111") {//8
						code[i] = 8;
					}
					else if (cryto == "0001011") {//9
						code[i] = 9;
					}
				}

				int tmp = (code[0] + code[2] + code[4] + code[6]) * 3 + code[1] + code[3] + code[5] + code[7];
				int sum = 0;
				for (int i = 0; i < 8; i++) {
					sum += code[i];
				}

				if (tmp % 10 == 0 && sum < check) {
					check = sum;
				}
				else if (tmp % 10 != 0) {
					check = 0;
				}
			}
		}
		printf("#%d %d\n", t, check);
	}
}