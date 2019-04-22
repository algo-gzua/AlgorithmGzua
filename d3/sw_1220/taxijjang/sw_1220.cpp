#include<iostream>
#define MAX 110

using namespace std;

int up = -1;
int down = 1;

bool check[MAX][MAX];
int arr[MAX][MAX];

//교착 상태를 찾는 함수
int deadlock(int NN) {
	bool judge = false; //교착 상태에 들어 갔는지 판단 하는 변수
	int tmp = 0; //현재 위치 전의 극을 저장하는 변수
	int cnt = 0; 

	int N = 1, S = 2;
	for (int i = 1; i <= NN; i++) {
		for (int j = 1; j <= NN; j++) {
			//judge가 false면 아직 교착 상태를 만나지 못함

			if (judge == false) {
				//교착 상태를 만나지 못한 상태에서 N극을 만나게 됫을때
				//교착 상태에 들어 갔음을 judge = true로 나타남
				if (arr[j][i] != 0) {
					judge = true;
					tmp = N;
					cnt++; //교착 상태에 들어가면 카운트를 증가 시켜줌
				}
				else if(arr[j][i] == 0){}

			}

			//현재 교착상태 진행 중 일때
			else if (judge == true) {
				if (arr[j][i] != 0) {
					//이때 NSNS와 같은 2번의 교착 상태가 발생 할 수 있으므로
					//이전상태의 극을 저장한 tmp와 현재 상태의 극을 비교
					//이때 N극에서 S극으로 갈때는 tmp를 S극 으로 저장
					//tmp가 S극이고 현재가 N극 일때에는 교착이 2번 발생하므로 
					//cnt를 증가 하고 tmp를 N극으로 저장
					if (tmp == N && arr[j][i] == S) {
						tmp = S;
					}
					if (tmp == S && arr[j][i] == N) {
						tmp = N;
						cnt++;
					}
					
				}
				else if (arr[j][i] == 0) {
					judge = false;
				}
			}
		}
		judge = false;
		tmp = 0;
	}
	return cnt;
}

int main(void) {
	for (int t = 1; t <= 10; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		//cnt는 테이블을 탐색 하면서 모든 자성체들이
		//교착상태인지 아닌지를 확인 하는 변수 하나라도 움직이면 0이 아니게 됨
		int cnt;

		//무한반복 시켜 교착이면 빠져 나옴
		do {
			cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (arr[i][j] == 1) {
						
						//N극은 S극을 향해 가게되므로 아래 밖으로 나가게되면 없어짐
						if (i+down == N+1) {
							arr[i][j] = 0;
						}

						//check배열은 이미 한번 움직인 자석을 또 다시 움직이지 않게 하는 배열
						//N극은 밑으로 가므로 밑에 빈공간인지 S극이 있는지 판단 후 행동을 결정
						else if (arr[i + down][j] == 0) {
							if (check[i][j] != true) {
								arr[i][j] = 0;
								arr[i + down][j] = 1;
								check[i + down][j] = true;
								cnt++;
							}
						}
					}

					else if (arr[i][j] == 2) {
						
						//S극은 N극을 향해 가게되므로 위 밖으로 나가게되면 없어짐
						if (i+up == 0) {
							arr[i][j] = 0;
						}

						//S극은 위로 가므로 위에 빈공간인지 N극이 있는지 판단 후 행동을 결정
						else if (arr[i + up][j] == 0) {
							if (check[i][j] != true) {
								arr[i][j] = 0;
								arr[i + up][j] = 2;
								cnt++;
								check[i + up][j] = true;
							}
						}
					}
				}
			}
			fill(&check[0][0], &check[MAX][MAX], false);

		} while (cnt != 0);

		printf("#%d %d\n",t,deadlock(N));

		printf("안녕");
		getchar();
	}
}