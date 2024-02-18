#include <iostream>
#include <vector>
#include <algorithm>

// 문자열 덧셈
std::string string_add(std::string a, std::string b) {
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	// a > b, always.
	if (a.size() < b.size()) {
		std::swap(a, b);
	}

	else if (a.size() == b.size()) {
		a += '0';
	}

	int i = 0, carry = 0;
	std::string sum = "";
	for (; i < b.size(); ++i) {
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		sum.push_back(num % 10 + '0');
		carry = num / 10;
	}

	a[i] += carry;

	// a가 남은 경우
	while (i < a.size()) {
		sum += a[i++];
	}

	if (sum[--i] == '0') {
		sum.pop_back();
	}

	std::reverse(sum.begin(), sum.end());

	return sum;
}

int main() {
	int n;
	while (std::cin >> n) {
		std::vector<std::string> dp(n + 1, "1");

		for (int i = 2; i <= n; ++i) {
			dp[i] = string_add(dp[i - 1], dp[i - 2]);
			dp[i] = string_add(dp[i], dp[i - 2]);
		}

		std::cout << dp[n] << " ";
	}
}