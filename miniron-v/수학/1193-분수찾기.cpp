#include <iostream>

int main() {
	int x;
	std::cin >> x;

	int sum = 1, i = 0;
	while (sum <= 10000000) {
		if (sum + ++i > x) {
			break;
		}
		sum += i;
	}

	int s = x - sum;
	int numerator = 1 + s, denominator = i - s;

	if (i % 2 == 0) {
		std::cout << numerator << "/" << denominator;
	}
	else {
		std::cout << denominator << "/" << numerator;
	}
}