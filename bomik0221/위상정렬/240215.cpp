#include <iostream>
#include <vector>
#include <queue>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(0, 0));
	std::vector<int> indegree(N + 1, 0);
	std::vector<int> sorted;

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	std::queue<int> q;
	for (int i = 1; i < N + 1; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int temp = q.front();
		sorted.push_back(temp);
		q.pop();
		for (int i = 0; i < graph[temp].size(); i++) {
			indegree[graph[temp][i]]--;
			if (indegree[graph[temp][i]] == 0) {
				q.push(graph[temp][i]);
			}
		}
	}

	for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	return 0;
}