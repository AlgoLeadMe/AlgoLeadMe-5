#include <iostream>

int main() {
	long long n, sum = 0, s=1;	std::cin >> n;
	

	while (n) {
		if (n & 1) {
			sum += s;
		}
		s *= 3; //3의 거듭제곱
		n >>= 1;	//n을 오른쪽으로 한 자리 밀어서 저장
	}
	std::cout << sum;
	return 0;
}