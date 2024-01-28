#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int answer[8];

void dfs(int count_dept, int idx)
{
    if (count_dept == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        answer[count_dept] = arr[i];
        dfs(count_dept + 1, i);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    dfs(0, 0);
}