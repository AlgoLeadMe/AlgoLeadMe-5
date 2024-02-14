#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	
	std::vector<int> t(n), p(n), max(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		std::cin >> t[i];
		std::cin >> p[i];
	}

	for (int i = 0; i < n; ++i) {
		int j = i + t[i];

		if (j <= n) {
			if (max[i] + p[i] > max[j]) {
				max[j] = max[i] + p[i];
			}
		}

		max[i + 1] = std::max(max[i + 1], max[i]);
	}

	std::cout << max[n];
}