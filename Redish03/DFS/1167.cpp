#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> tree(100001);
int max_dist = -99;
vector<bool> path;
int max_node = 0;

void dfs(int node, int distance)
{
    if (path[node])
    {
        return;
    }
    if (distance > max_dist)
    {
        max_dist = distance;
        max_node = node;
    }
    path[node] = true;
    for (int i = 0; i < tree[node].size(); i++)
    {
        int nnode = tree[node][i].first;
        int ndist = tree[node][i].second;
        dfs(nnode, distance + ndist);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;
    int a, node, dist;
    path.resize(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        cin >> a;
        while (true)
        {
            cin >> node;
            if (node == -1)
                break;
            cin >> dist;

            tree[a].push_back({node, dist});
        }
    }
    dfs(1, 0);
    path.assign(V + 1, false);
    dfs(max_node, 0);

    cout << max_dist;
}