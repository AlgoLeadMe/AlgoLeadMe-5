#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int start_node, end_node;
int distance_value[1001];
vector<pair<int, int>> bus[100001];

void Dijkstra()
{
    for (int i = 1; i <= N; i++)
    {
        distance_value[i] = 999999999;
    }

    // 시작 노드는 거리가 0이다.
    distance_value[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start_node});

    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int cur_node = pq.top().second;

        pq.pop();

        // 만약 현재거리가 최솟값보다 크다면 (계산 횟수 줄이기 용도)
        if (distance_value[cur_node] < curdist)
            continue;
        for (int i = 0; i < bus[cur_node].size(); i++)
        {
            int next_node = bus[cur_node][i].first;
            int ncost = bus[cur_node][i].second;

            if (curdist + ncost < distance_value[next_node])
            {
                distance_value[next_node] = curdist + ncost;
                pq.push({curdist + ncost, next_node});
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;

        /*
        문제에서는 a -> b로 이동하는 한 방향으로만 주어졌지만,
        일반적인 경우에는 양방향 (a <-> b)로 주어지는 경우도
        있어서 참고하면 좋을 것 같다.
        */
        bus[a].push_back({b, d});
        // 양방향일때 다음을 추가해준다.
        // bus[b].push_back({a, d});
    }

    cin >> start_node >> end_node;
    Dijkstra();
    cout << distance_value[end_node];
}