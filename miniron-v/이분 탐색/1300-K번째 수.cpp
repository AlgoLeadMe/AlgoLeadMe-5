#include <iostream>

// [n][n] 배열에서 upper 이하 수의 개수를 센다.
long countNum(long n, long upper) {
	long count = 0;

	for (long i = 1; i <= n && i <= upper; ++i) {
		count += std::min(upper / i, n);
	}

	return count;
}

int main() {
	long n, k;
	std::cin >> n >> k;

	long low = 0, high = k;
	long mid = 0;

	while (low + 1 < high) {
		mid = (low + high) / 2;
		long count = countNum(n, mid);

		if (count < k) {
			low = mid;
		}

		else if (count >= k) {
			high = mid;
		}
	}

	std::cout << high;
}