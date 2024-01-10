//백준 2841번 슈퍼 마리오
#include <iostream>
#define MUSHROOM 10
/*버섯의 개수를 나타내는 상수. 점수 배열 인덱스와 반복문에서 사용.
현재 코드에서는 큰 의미가 없어도 상수를 여러 번 사용하면 가독성이
떨어질 수 있어서 클린코드를 위해 최근 습관화하는 부분입니다.*/

int main() {
	int score[MUSHROOM] = { 0 };
	int answer = 0, temp = 0;

	//점수 입력
	for (int i = 0; i < MUSHROOM; i++) {
		std::cin >> score[i];
	}
	
	//검사
	for (int j = 0; j < MUSHROOM; j++) {
		temp += score[j];

		//점수의 합이 100 이하일 때는 바로 answer에 저장
		if (temp <= 100) answer = temp;

		//점수의 합이 100이 넘어서는 시점에는 100보다 작은 쪽과 100보다 큰 쪽을 비교한다.
		else {
			//100보다 작은 쪽이 100에 가까울때는 작은 쪽을 선택
			if (100 - answer < temp - 100)	continue;
			//그 외의 경우에는 큰 쪽을 선택
			else answer = temp;
		}

		//합이 딱 100이면 break;
		if (answer == 100)	 break;
	}

	//답을 cmd에 출력
	std::cout << answer;
	return 0;
}