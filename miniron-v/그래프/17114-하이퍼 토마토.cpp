// https://saens.tistory.com/16 참고
#include <iostream>
#include <vector>
#include <queue>

int s[11], dist[11] = { 1 };
int zero_count = 0;

std::queue<int> ripe_tomato;

int main() {
	// 입력
	int total = 1;
	for (int i = 0; i < 11; i++) {
		std::cin >> s[i];
		total *= s[i];
	}

	std::vector<int> box(total);
	for (int i = 0; i < total; i++) {
		std::cin >> box[i];

		if (box[i] == 0) {
			++zero_count;
		}
		if (box[i] == 1) {
			ripe_tomato.push(i);
		}
	}

	// 사전 작업
	for (int i = 1; i < 11; i++) {
		dist[i] = s[i - 1] * dist[i - 1];
	}

	// 계산 (BFS)
	int day = -1;
	int cur_pos;
	while (ripe_tomato.empty() == false) {
		for (int repeat = ripe_tomato.size(); repeat > 0; --repeat) {
			cur_pos = ripe_tomato.front();
			ripe_tomato.pop();

			for (int dir = 0; dir < 22; ++dir) {
				// 0부터 11까지 2개씩 생성
				int k = dir / 2,
					// 부호(dir이 홀수면 -, 짝수면 +)
					sign = 1 - 2 * (dir % 2),
					// 현재 위치 +- dist[k](거리)
					next_pos = cur_pos + sign * dist[k],
					// 차원의 크기(1차원은 x축, 2차원은 y축...블로그 참고)
					dim_size = dist[k] * s[k],
					// 범위 판정용 변수
					last_mod = cur_pos % dim_size,
					next_mod = next_pos % dim_size;

				// 배열 내 index인가?
				if (0 <= next_pos && next_pos < total
					// 위치와 mod의 부호가 일치하는가?
					&& sign * (next_mod - last_mod) > 0
					// 안 익은 토마토가 맞는가?
					&& box[next_pos] == 0)
				{
					// 토마토 익히고, 0개수 줄이고, 큐에 푸시
					box[next_pos] = 1;
					--zero_count;
					ripe_tomato.push(next_pos);
				}
			}
		}

		day++;
	}

	if (zero_count > 0) {
		day = -1;
	}

	std::cout << day;
}