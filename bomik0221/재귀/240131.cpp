#include <iostream>

int N;

std::string line = "____";

std::string whatis = "\"재귀함수가 뭔가요?\"";

std::string sunin[3] =
{ "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};

std::string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";

std::string dabbyeon = "라고 답변하였지.";

void chatbot(int a) {
	if (N == a) {
		std::cout << whatis << "\n" << answer << "\n" << dabbyeon << "\n";
		int remove = 4;
		for (int i = 0; i < N; i++) {
			std::cout << dabbyeon.substr(remove) << "\n";
			remove += 4;
		}
		return;
	}
	std::cout <<whatis << "\n" << sunin[0] << "\n" << sunin[1] << "\n" << sunin[2] << "\n";
	whatis = line + whatis;
	sunin[0] = line + sunin[0];	sunin[1] = line + sunin[1];	sunin[2] = line + sunin[2];
	answer = line + answer;
	dabbyeon = line + dabbyeon;
	
	chatbot(a + 1);
}

int main() {
	std::cin >> N;

	std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

	chatbot(0);

	return 0;
}