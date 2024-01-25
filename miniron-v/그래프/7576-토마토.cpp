#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int n, m;
std::vector<std::vector<int>> box;

// (x, y) 위치의 토마토가 상자 안의 안 익은 토마토인지 검사한다.
bool promise(int x, int y) {
	if (x < 0 || m <= x || y < 0 || n <= y || box[x][y] != 0) {
		return false;
	}

	return true;
}

// 모든 토마토가 익었는지 검사한다.
bool isAllTomatoesRipe() {
	for (auto& line : box) {
		for (auto& i : line) {
			if (i == 0) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	std::cin >> n >> m;
	
	box.resize(m, std::vector<int>(n));
	std::queue<std::tuple<int, int, int>> ripe_tomato;	// x, y, time

	// 입력
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> box[i][j];
			if (box[i][j] == 1) {
				ripe_tomato.emplace(std::make_tuple(i, j, 0));
			}
		}
	}

	int offset[4][2] = {
		{ -1, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 0, -1 }
	};

	// 계산 (BFS)
	int day = 0;
	while (ripe_tomato.empty() == false) {
		std::tuple<int, int, int> tomato = ripe_tomato.front();
		ripe_tomato.pop();
		day = std::get<2>(tomato);

		for (int i = 0; i < 4; i++) {
			int new_x = std::get<0>(tomato) + offset[i][0];
			int new_y = std::get<1>(tomato) + offset[i][1];

			if (promise(new_x, new_y)) {
				box[new_x][new_y] = 1;
				ripe_tomato.emplace(std::make_tuple(new_x, new_y, day + 1));
			}
		}
	}

	if (isAllTomatoesRipe() == false) {
		day = -1;
	}

	std::cout << day;
}