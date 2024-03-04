#include <iostream>
#include <vector>

int main() {
	int N; std::cin >> N;
	std::vector<int> game(N+1, 0);
	game[1] = 1;	game[3] = 1;	//상근이는 1, 창영이는 2

	for (int i = 2; i <= N; i++) {
		if (game[i - 1] == 1) {
			game[i] = 2;
			if(i+2 <=N)	game[i + 2] = 2;
		}
		else {
			game[i] = 1;
			if (i + 2 <= N)	game[i + 2] = 1;
		}
	}

	if (game[N] == 1)	std::cout << "SK";
	else std::cout << "CY";

	return 0;
}