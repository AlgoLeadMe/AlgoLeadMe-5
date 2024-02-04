#include <iostream>
#include <vector>

int main() {
	// 입력
	int length;
	std::cin >> length;

	std::vector<int> jump_chance(length);
	for (int i = 0; i < length; i++) {
		std::cin >> jump_chance[i];
	}

	// 계산
	std::vector<int> dp(length, -1);
	dp[0] = 0;

	for (int cur = 0; cur < length; ++cur) {
		// 도달할 수 없는 칸이 있다면 종료
		if (dp[cur] == -1) {
			break;
		}

		for (int jump = 1; jump <= jump_chance[cur] && cur + jump < length; ++jump) {
			// 아직 도달한 적 없다면 갱신
			if (dp[cur + jump] == -1) {
				dp[cur + jump] = dp[cur] + 1;
			}

			// 더 적은 점프로 도달했다면 갱신
			else if (dp[cur] + 1 < dp[cur + jump]) {
				dp[cur + jump] = dp[cur] + 1;
			}
		}
	}

	std::cout << dp[length - 1];
}