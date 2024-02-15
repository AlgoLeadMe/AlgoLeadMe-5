#include <iostream>
#include <string.h>	//memset 사용

int T, M, N, K;
int worm = 0;	//지렁이 수

int field[50][50] = { 0 };

//방향
int xpos[4] = { 0,0,-1,1 };
int ypos[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int X = x + xpos[i];
		int Y = y + ypos[i];

		//N*M 배열 안에 있으면서 해당 칸의 값이 1일때만 수행
		if (X >= 0 && X < N && Y >= 0 && Y < M && field[X][Y] == 1) {
			field[X][Y] = 0;
			dfs(X, Y);
		}
	}
	return;
}

int main() {
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> M >> N >> K;
		
		for (int i = 0; i < K; i++) {
			int a, b;
			std::cin >> a >> b;
			field[b][a] = 1;
		}

		//배추를 발견하면 dfs 수행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1) {
					dfs(i, j);
					worm++;
				}
			}
		}
		std::cout << worm << "\n";

		//각 테스트케이스마다 재사용 할 변수들 초기화 : 밭 배열과 지렁이 수
		for (int i = 0; i < 50; i++) {
			memset(field[i], 0, sizeof(int)*50);
		}
		worm = 0;
	}

	return 0;
}