#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[1026][1026];
int sum_arr[1026][1026];

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            row_sum += arr[i][j];

            if (i == 0)
            {
                sum_arr[i][j] = row_sum;
            }
            else
            {
                sum_arr[i][j] = sum_arr[i - 1][j] + row_sum;
            }
        }
    }
}

int findSumAToB(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
    {
        return arr[x1][y1];
    }
    else if (x1 == 0 && y1 == 0)
    {
        return sum_arr[x2][y2];
    }
    else if (x1 == 0)
    {
        return sum_arr[x2][y2] - sum_arr[x2][y1 - 1];
    }
    else if (y1 == 0)
    {
        return sum_arr[x2][y2] - sum_arr[x1 - 1][y2];
    }
    else
    {
        return sum_arr[x2][y2] - (sum_arr[x2][y1 - 1] + sum_arr[x1 - 1][y2]) + sum_arr[x1 - 1][y1 - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << findSumAToB(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
    }
}