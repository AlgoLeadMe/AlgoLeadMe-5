#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;

    cin >> T;
    while (T--)
    {
        int N, M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            q.push({num, i});
            pq.push(num);
        }
        int answer = 1;
        while (true)
        {
            int priority = q.front().first;
            int order = q.front().second;

            if (priority != pq.top())
            {
                q.pop();
                q.push({priority, order});
            }
            else
            {
                if (order == M)
                    break;
                else
                {
                    q.pop();
                    pq.pop();
                    answer++;
                }
            }
        }
        cout << answer << '\n';
    }
}