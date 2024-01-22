#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N, 0), B(N, 0);

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), std::greater<int>());
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	std::cout << sum;

	return 0;
}