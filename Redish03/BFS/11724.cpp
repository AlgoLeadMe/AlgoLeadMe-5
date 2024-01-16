#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<bool> visited(1001, false);
int N, M;
int count_tree = 0;
vector<vector<int>> arr(1001);

void bfs(int start)
{
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < arr[x].size(); i++)
        {
            int nx = arr[x][i];

            if (visited[nx])
                continue;

            visited[nx] = true;
            q.push(nx);
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        // 2차원 배열에 트리 저장
        int a, b;

        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;
        bfs(i);

        count_tree++;
    }

    cout << count_tree;
}