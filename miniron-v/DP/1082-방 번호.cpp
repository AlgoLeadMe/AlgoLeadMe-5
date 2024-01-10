#include <iostream>
#include <vector>

int main() {
	// 입력
	int n;
	std::cin >> n;

	int min_index = 0;
	std::vector<int> cost(n);
	std::vector<int> upgrade(n);

	for (int i = 0; i < n; i++) {
		std::cin >> cost[i];
		// 같은 값이면 큰 수가 좋다.
		if (cost[i] <= cost[min_index]) { min_index = i; }
	}

	for (int i = 0; i < n; i++) {
		upgrade[i] = cost[i] - cost[min_index];
	}

	int m;
	std::cin >> m;

	// 계산
	int place = m / cost[min_index];	// 자리 개수
	std::vector<int> num;

	do {
		num.assign(place, min_index);

		int balance = m - place * cost[min_index];

		// 모든 자릿수에 대해 반복 (i: 자릿수)
		for (int i = 0; i < place; i++) {
			// min_index보다 큰 수에 대해서만 비교 (j: 숫자, 0 ~ 9)
			for (int j = n - 1; j > min_index; j--) {
				if (balance - upgrade[j] >= 0) {
					balance -= upgrade[j];
					num[i] = j;
					break;	// 다음 자릿수로 이동
				}
			}

			// 잔액이 0원이 되면 바로 종료
			if (balance == 0) { break; }
		}

		// 한 자리 숫자가 아닌데 첫 자리가 0이라면, 자릿수를 1 줄이고 반복한다.
	} while (place-- > 1 && num[0] == 0);

	// 출력
	for (auto& i : num) {
		std::cout << i;
	}
}