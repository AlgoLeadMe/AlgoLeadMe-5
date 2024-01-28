#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int current[3];

    int min_prev[3];
    int min_current[3];
    int max_prev[3];
    int max_current[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> min_prev[i];
        max_prev[i] = min_prev[i];
    }
    if (N == 1)
    {
        cout << max(max_prev[0], max(max_prev[1], max_prev[2])) << " ";
        cout << min(min_prev[0], min(min_prev[1], min_prev[2]));
        return 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> current[j];
        }

        min_current[0] = current[0] + min(min_prev[0], min_prev[1]);
        min_current[1] = current[1] + min(min_prev[0], min(min_prev[1], min_prev[2]));
        min_current[2] = current[2] + min(min_prev[1], min_prev[2]);

        max_current[0] = current[0] + max(max_prev[0], max_prev[1]);
        max_current[1] = current[1] + max(max_prev[0], max(max_prev[1], max_prev[2]));
        max_current[2] = current[2] + max(max_prev[1], max_prev[2]);

        for (int j = 0; j < 3; j++)
        {
            min_prev[j] = min_current[j];
            max_prev[j] = max_current[j];
        }
    }

    cout << max(max_current[0], max(max_current[1], max_current[2])) << " ";
    cout << min(min_current[0], min(min_current[1], min_current[2]));
}