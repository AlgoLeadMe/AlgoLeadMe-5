#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<bool> isBroken(10, false);

// 자릿수를 반환
int countDigits(int n) {
	if (n == 0) {
		return 1;
	}

	int count = 0;

	while (n > 0) {
		count++;
		n /= 10;
	}

	return count;
}

// 해당 채널을 바로 만들 수 있는 지 검사한다.
bool canMakeChannel(int channel) {
	// 0번 채널을 만들 경우
	if (channel == 0) {
		if (isBroken[0]) {
			return false;
		}

		return true;
	}

	int r;

	while (channel > 0) {
		// 각 자릿수를 검사
		r = channel % 10;

		// 쓸 수 없는 값이면 false
		if (isBroken[r]) {
			return false;
		}

		// 검사한 자리 제거
		channel /= 10;
	}

	return true;
}

int main() {
	// 입력
	int n, m;
	std::cin >> n >> m;

	int temp = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		isBroken[temp] = true;
	}

	// 계산
	// 모든 숫자 버튼이 고장난 경우 +, -만 조작
	// 98 ~ 103번 채널은 +, -만 하는 게 더 이득
	if (m == 10 || (98 <= n && n <= 103)) {
		std::cout << abs(n - 100);
		return 0;
	}

	int answer;
	for (int i = 0; ; i++) {
		// + 버튼 조작
		if (n - i >= 0 && canMakeChannel(n - i)) {
			answer = countDigits(n - i) + i;
			break;
		}

		// - 버튼 조작
		if (canMakeChannel(n + i)) {
			answer = countDigits(n + i) + i;
			break;
		}
	}

	// +, -로 조작한 횟수보다 i가 커지면, +, -로 조작
	if (answer > abs(n - 100)) {
		answer = abs(n - 100);
	}

	std::cout << answer;
}