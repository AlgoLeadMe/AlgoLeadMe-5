#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, E;
int start_node, end_node;
int distance_value[1001];
vector<pair<int, int>> node[100001];

void Dijkstra()
{
    for (int i = 1; i <= N; i++)
    {
        distance_value[i] = 999999999;
    }

    distance_value[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start_node});

    while (!pq.empty())
    {
        int x = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (distance_value[u] < x)
            continue;
        for (int i = 0; i < node[u].size(); i++)
        {
            int next = node[u][i].first;
            int cost = node[u][i].second;

            if (x + cost < distance_value[next])
            {
                distance_value[next] = x + cost;
                pq.push({x + cost, next});
            }
        }
    }
}

int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;

        node[a].push_back({b, d});
        // node[b].push_back({a, d});
    }

    cin >> start_node >> end_node;
    Dijkstra();
    cout << distance_value[end_node];
}