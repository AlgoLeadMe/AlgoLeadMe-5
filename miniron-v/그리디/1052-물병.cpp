// 그리디하게 푸는 법
#include <iostream>
#include <vector>

int main() {
	int n, k;
	std::cin >> n >> k;

	// 최대한 많은 물병을 써서 k - 1개의 물병을 만든다.
	for (int i = 0; i < k - 1; i++) {
		int bottles = 1;
		for (; bottles * 2 < n; bottles *= 2);

		n -= bottles;
	}

	// 남은 n개의 물병보다 큰, 가장 작은 2의 지수승을 구한다.
	int need = 1;
	for (;  need < n; need *= 2);

	std::cout << need - n;
}