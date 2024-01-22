#include <iostream>
#include <vector>

std::vector<bool> is_prime;

void eratosthenes() {
	for (int i = 2; i < is_prime.size(); i++) {
		if (is_prime[i] == false) {
			continue;
		}

		for (int j = i * 2; j < is_prime.size(); j += i) {
			is_prime[j] = false;
		}
	}
}

// 다음 소수를 반환, 배열 범위 초과 시 size 반환
int moveToNextPrime(int i) {
	for (i++; i < is_prime.size(); i++) {
		if (is_prime[i] == true) {
			break;
		}
	}

	return i;
}

int main() {
	// 입력
	int n;
	std::cin >> n;

	// 에라토스테네스의 체 생성
	is_prime.assign(n + 1, true);
	eratosthenes();

    // 계산
	int start = 2, end = 2;
 	int sum = 2, count = 0;
	
	while (start < is_prime.size() && end < is_prime.size() && start <= end) {
		if (sum == n) {
;			count++;

			sum -= start;
			start = moveToNextPrime(start);
		}

		else if (sum < n) {
			end = moveToNextPrime(end);
			sum += end;
		}

		else if (sum > n) {
			sum -= start;
			start = moveToNextPrime(start);
		}
	}

    // 출력
	std::cout << count;
}