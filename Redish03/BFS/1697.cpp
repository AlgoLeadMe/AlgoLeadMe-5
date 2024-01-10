#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int start, endPoint;
bool visited[99999999] = {
    false,
};

void bfs()
{
    while (!q.empty())
    {
        int cur_number = q.front().first;
        int count = q.front().second;
        q.pop();
        if (cur_number == endPoint)
        {
            cout << count;
            return;
        }
        if (visited[cur_number] || (cur_number < 0 || cur_number > 100001))
            continue;
        visited[cur_number] = true;
        count++;
        q.push({cur_number - 1, count});
        q.push({cur_number + 1, count});
        q.push({cur_number * 2, count});
    }
}

int main()
{
    cin >> start >> endPoint;
    q.push({start, 0});
    bfs();
}