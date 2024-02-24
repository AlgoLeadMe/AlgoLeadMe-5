#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int N, M;
int current[8];
int previ[8];
bool used[8];

bool check_duplicate()
{
    for (int i = 0; i < M; i++)
    {
        if (current[i] != previ[i])
        {
            return false;
        }
    }
    return true;
}

void find_arr(int count)
{
    if (count == M)
    {
        if (check_duplicate())
        {
            return;
        }
        for (int i = 0; i < M; i++)
        {
            previ[i] = current[i];
            cout << current[i] << " ";
        }
        cout << '\n';

        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (used[i] || tmp == arr[i])
            continue;
        current[count] = arr[i];
        tmp = arr[i];
        used[i] = true;
        find_arr(count + 1);
        used[i] = false;
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

    find_arr(0);
}