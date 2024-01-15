//백준 1094번 막대기
#include <iostream>

int main() {
	int X;
	std::cin >> X;

	int count = 0;

	while (X > 0) {
		count += X & 1;
		X = X >> 1;
	}

	std::cout << count;

	return 0;
}