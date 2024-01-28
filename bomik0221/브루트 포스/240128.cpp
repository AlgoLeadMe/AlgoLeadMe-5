#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  //accumulate 사용을 위해 추가한 헤더


int main() {
	std::vector<int> dwarf(9, 0);
	std::vector<bool> check(9, false);	//어느 놈이 범인인지를 알아내기 위해 사용하는 bool 배열
	for (int i = 0; i < dwarf.size(); i++) {
		std::cin >> dwarf[i];
	}

	std::sort(dwarf.begin(), dwarf.end());

	//찾아야하는 난쟁이 두마리 키의 합 == 모든 난쟁이 키의 합에서 100을 뺀 값
	int overhundred = std::accumulate(dwarf.begin(), dwarf.end(), 0) - 100;

	bool found = false;
	for (int i = 0; i < dwarf.size(); i++) {
		for (int j = dwarf.size()-1; j > 0; j--) {
			if (dwarf[i] + dwarf[j] == overhundred) {
				check[i] = true;
				check[j] = true;
				found = true;
				break;
			}
		}
		//이중 반복문 탈출용 코드
		if (found == true) break;
	}

	for (int i = 0; i < dwarf.size(); i++) {
		if(check[i] == false)	std::cout << dwarf[i] << "\n";
	}

	return 0;
}