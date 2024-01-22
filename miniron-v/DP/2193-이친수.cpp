#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<long long> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[n];
}