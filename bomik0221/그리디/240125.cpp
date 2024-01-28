#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;	int answer = 0;
	std::cin >> N;
	std::vector<int> P(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		std::cin >> P[i];
	}

	std::sort(P.begin(), P.end());

	int j = N;
	for (int i = 1; i <= N; i++) {
		answer += P[i] * j--;
	}

	std::cout << answer;

	return 0;
}