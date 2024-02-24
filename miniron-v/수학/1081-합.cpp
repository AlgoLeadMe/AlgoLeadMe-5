#include <iostream>

long long gaussSum(long long k) {
	if (k % 2 == 0) {
		return (k / 2) * (k + 1);
	}

	return ((k + 1) / 2) * k;
}

long long getSumOfPlace(long long n) {
	if (n < 1) {
		return 0;
	}

	long long answer = gaussSum(n);

	long long d = 10;
	while ((n / d) > 0) {
		long long q = n / d;
		long long r = n % d;

		answer -= 9 * (gaussSum(q - 1) * d + q * (r + 1));

		d *= 10;
	}

	return answer;
}

int main() {
	long long l, u;
	std::cin >> l >> u;

	std::cout << getSumOfPlace(u) - getSumOfPlace(l - 1);
}