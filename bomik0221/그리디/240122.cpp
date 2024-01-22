#include <iostream>

int main() {
	std::string S;
	std::cin >> S;
	
	int k = 0;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] > S[i + 1]) {
			k++;
		}
	}
	std::cout << k;

	return 0;
}