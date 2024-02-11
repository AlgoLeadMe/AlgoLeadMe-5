#include <iostream>
#include <vector>
#include <queue>

int n, k, w;

// dp (시간 계산)
std::vector<int> cost;
std::vector<int> min_cost;

// 위상정렬 (순서 지정)
std::vector<std::vector<int>> graph;
std::vector<int> inDegree;
std::queue<int> queue;

std::vector<int> sorted;

void input() {
	std::cin >> n >> k;
	
	cost.assign(n + 1, 0);
	min_cost.assign(n + 1, 0);

	graph.assign(n + 1, std::vector<int>(0));
	inDegree.assign(n + 1, 0);

	sorted.clear();

	for (int i = 1; i <= n; ++i) {
		std::cin >> cost[i];
	}

	int a1, a2;
	while (k--) {
		std::cin >> a1 >> a2;
		graph[a1].push_back(a2);
		++inDegree[a2];
	}

	std::cin >> w;
}

void topologySort() {
	for (int i = 1; i < inDegree.size(); i++) {
		if (inDegree[i] == 0) {
			queue.push(i);
		}
	}

	int a;
	while (queue.empty() == false) {
		a = queue.front();
		queue.pop();

		sorted.push_back(a);

		for (int i : graph[a]) {
			if (--inDegree[i] == 0) {
				queue.push(i);
			}
		}
	}
}

int minCost() {
	for (int a : sorted) {
		min_cost[a] += cost[a];

		for (int i : graph[a]) {
			if (min_cost[a] > min_cost[i]) {
				min_cost[i] = min_cost[a];
			}
		}
	}

	return min_cost[w];
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		input();

		topologySort();

		std::cout << minCost() << "\n";
	}
}