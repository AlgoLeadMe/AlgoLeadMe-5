#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int n, m, h;
int box[100][100][100];

// (x, y) 위치의 토마토가 상자 안의 안 익은 토마토인지 검사한다.
bool promise(int i, int j, int k) {
	if (i < 0 || h <= i
		|| j < 0 || m <= j 
		|| k < 0 || n <= k 
		|| box[i][j][k] != 0) {
		return false;
	}

	return true;
}

// 모든 토마토가 익었는지 검사한다.
bool isAllTomatoesRipe() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (box[i][j][k] == 0) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	std::cin >> n >> m >> h;
	
	std::queue<std::tuple<int, int, int>> ripe_tomato;	// i, j, k

	// 입력
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				std::cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					ripe_tomato.push(std::make_tuple(i, j, k));
				}
			}
		}
	}

	std::vector<std::vector<int>> offset = {
		{ -1, 0, 0 },
		{ 1, 0, 0 },
		{ 0, -1, 0 },
		{ 0, 1, 0 },
		{ 0, 0, -1 },
		{ 0, 0, 1 }
	};

	// 계산 (BFS)
	int day = -1;
	while (ripe_tomato.empty() == false) {
		for (int a = ripe_tomato.size(); a > 0; --a) {
			int i, j, k;
			std::tie(i, j, k) = ripe_tomato.front();
			ripe_tomato.pop();

			for (int dir = 0; dir < 6; dir++) {
				int new_i = i + offset[dir][0];
				int new_j = j + offset[dir][1];
				int new_k = k + offset[dir][2];

				if (promise(new_i, new_j, new_k)) {
					box[new_i][new_j][new_k] = 1;
					ripe_tomato.push(std::make_tuple(new_i, new_j, new_k));
				}
			}
		}
		day++;
	}

	if (isAllTomatoesRipe() == false) {
		day = -1;
	}

	std::cout << day;
}