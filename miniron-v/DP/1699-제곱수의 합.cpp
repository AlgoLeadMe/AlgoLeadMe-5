#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= n; ++i) {
		int min_index = i - 1;
		
		for (int j = 2; j * j <= i; ++j) {
			if (dp[i - (j * j)] < dp[min_index]) {
				min_index = i - (j * j);
			}
		}

		dp[i] = dp[min_index] + 1;
	}

	std::cout << dp[n];
}