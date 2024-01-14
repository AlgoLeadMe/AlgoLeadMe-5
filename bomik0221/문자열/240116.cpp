#include <iostream>
#include <vector>
#define NUM 5

bool FBI(std::string agent) {
	for (int i = 0; i < agent.size(); i++) {
		if (agent[i] == 'F' && agent[i + 1] == 'B' && agent[i + 2] == 'I') return true;
	}
	return false;
}

int main() {
	std::string agent[NUM];
	std::vector<int> answer;

	for (int i = 0; i < NUM; i++) {
		std::cin >> agent[i];
		if (FBI(agent[i]) == true)	answer.push_back(i + 1);
	}

	if (answer.empty())
		std::cout << "HE GOT AWAY!";
	else {
		for (int i = 0; i < answer.size(); i++) {
			printf("%d ", answer[i]);
		}
	}
	return 0;
}