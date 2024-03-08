#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));

	// INF와 자기 자신을 0으로 초기화하는 과정이 입력에 포함됨.
	// 즉, 모든 간선이 연결되어 있음.
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cin >> graph[i][j];
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	while (m--) {
		int a, b, c;
		std::cin >> a >> b >> c;

		std::cout << ((graph[a][b] <= c) ? "Enjoy other party\n" : "Stay here\n");
	}
}