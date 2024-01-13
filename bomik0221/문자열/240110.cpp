//백준 1181번 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>

//비교함수
bool compare(std::string a, std::string b) {
	if (a.size() == b.size())	return a < b;	//길이가 같으면 사전 순으로 정렬
	return a.size() < b.size();					//길이가 짧은 순으로 정렬
}

int main() {
	int n; std::cin >> n;
	std::vector<std::string> word;

	std::string temp;
	for (int i = 0; i < n; i++) {
		//단어 벡터에 입력받기
		std::cin >> temp;
		word.push_back(temp);
	}
	
	sort(word.begin(), word.end(), compare);	//정렬

	//출력
	for (int i = 0; i < n; i++) {
		//중복된 단어일 경우 최초 한 번만 출력하고 나머지는 출력하지 않는다.
		if (i !=0 && word[i - 1] == word[i])	continue;
		std::cout << word[i] << std::endl;
	}

	return 0;
}