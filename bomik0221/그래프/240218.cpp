#include <iostream>
#include <vector>
#include <queue>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(0, 0));
	std::vector<int> indegree(N + 1, 0);
	std::vector<int> sorted;

	//그래프 입력 받기
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	//위상정렬의 초기 상태
	std::queue<int> q;
	for (int i = 1; i < N + 1; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			break;	//쉬운 문제는 먼저 출력하라는 조건이 있으므로 큐에 문제 하나가 들어오면 바로 다음 과정으로 넘어가야함.
		}
	}
	//위상정렬 진행
	while (!q.empty()) {
		int temp = q.front();
		sorted.push_back(temp);
		q.pop();
		indegree[temp] = -1;
		for (auto next_node : graph[temp]) {
			indegree[next_node]--;
		}
		for (int i = 1; i < N + 1; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				break;
			}
		}
	}

	//답 출력
	for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	return 0;
}