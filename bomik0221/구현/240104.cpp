#include <iostream>
#include <string>
#include <vector>

int main() {
	int N, answer = 1; 	std::string seat;
	std::cin >> N >> seat;

	for (int i = 0; i < N; i++) {
		if (seat[i] == 'L') {
			i++;
			answer++;
		}
		else {
			answer++;
		}
		if (answer == N)	break;
	}

	std::cout << answer;
	return 0;
}