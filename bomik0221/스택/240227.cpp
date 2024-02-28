#include <iostream>
#include <stack>

int main() {
	std::string S;
	std::cin >> S;
	std::stack<int>stack;

	for (int num = 0; num < S.size(); num++) {
		if (!stack.empty() && stack.top() == 1 && S[num] == ')') stack.pop();
		else {
			if (S[num] == '(')	stack.push(1);
			else stack.push(2);
		}
	}
	std::cout << stack.size();
	return 0;
}
