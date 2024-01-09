#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// 입력
	int n;
	std::cin >> n;

	std::vector<int> nums(n, 0);

	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	int s;
	std::cin >> s;

	// 계산
	int start = 0, end = s;
	while (start < nums.size() && s > 0) {
		if (end >= nums.size()) {
			end = nums.size() - 1;
		}

		int max_index = std::max_element(nums.begin() + start, nums.begin() + end + 1) - nums.begin();
		
		// 최댓값을 맨 앞으로 땡겨온다.
		while (max_index > start) {
			std::swap(nums[max_index], nums[max_index - 1]);
			max_index--; s--;
		}

		// 범위 재설정
		start++; end = start + s;
	}

	// 출력
	for (int i = 0; i < n - 1; i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << nums[nums.size() - 1];

	return 0;
}
