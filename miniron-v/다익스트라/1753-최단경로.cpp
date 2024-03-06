#include <iostream>
#include <vector>
#include <queue>

const int INF = 3000001;

std::vector<int> dijkstra(int start, int n, std::vector<std::vector<std::pair<int, int>>>& graph) {
	std::vector<int> min_weight(n + 1, INF);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	min_weight[start] = 0;
	pq.push({ 0, start });

	while (pq.empty() == false) {
		int cur_weight = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for (auto& pair : graph[cur_node]) {
			int next_node = pair.first;
			int next_weight = cur_weight + pair.second;

			if (next_weight < min_weight[next_node]) {
				min_weight[next_node] = next_weight;
				pq.push({ next_weight, next_node});
			}
		}
	}

	return min_weight;
}

int main() {
	// 입력
	int V, E, start;
	std::cin >> V >> E >> start;

	std::vector<std::vector<std::pair<int, int>>> graph(V + 1);
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;

		graph[u].push_back({v, w});
	}
	
	// 계산
	std::vector<int> min_weight = dijkstra(start, V, graph);

	// 출력
	for (int i = 1; i < min_weight.size(); ++i) {
		if (min_weight[i] == INF) {
			std::cout << "INF\n";
			continue;
		}

		std::cout << min_weight[i] << "\n";
	}
}