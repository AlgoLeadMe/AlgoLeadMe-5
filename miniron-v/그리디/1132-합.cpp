#include <iostream>
#include <vector>
#include <algorithm>

bool isAllCharUsed(std::vector<long long>& weight) {
	for (auto& i : weight) {
		if (i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int n;
	std::cin >> n;

	std::vector<long long> weight(10, 0);
	std::vector<bool> is_not_zero(10, false);

	while (n--) {
		std::string str;
		std::cin >> str;

		// 가중치 계산 및 저장
		long long exp = 1;

		for (int i = str.size() - 1; i >= 0; i--) {
			weight[str[i] - 'A'] += exp;
			exp *= 10;
		}

		is_not_zero[str[0] - 'A'] = true;
	}

	// 모든 알파벳이 쓰인 경우, 첫 자리가 0이 아님을 고려한다.
	if (isAllCharUsed(weight)) {
		// 0을 줄 자리 고르기
		int min_index = -1;
		for (int i = 0; i < is_not_zero.size(); i++) {
			if (is_not_zero[i]) {
				continue;
			}

			// min_index를 최소 가중치로 갱신
			if (min_index == -1 || weight[i] < weight[min_index]) {
				min_index = i;
			}
		}

		weight[min_index] = 0;	// 가중치가 가장 작은, 0이 될 수 있는 애한테 0을 준다.
	}

	// weight를 기준으로 내림차순 정렬
	std::sort(weight.begin(), weight.end(), std::greater<long long>());

	long long answer = 0;
	int num = 9;

	// 가중치가 가장 큰 애부터, 가장 큰 숫자와 곱해 합한다.
	for (auto& i : weight) {
		answer += i * num--;
	}

	std::cout << answer;
}