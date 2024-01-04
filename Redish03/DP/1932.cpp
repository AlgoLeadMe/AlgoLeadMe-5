#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];

void input()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void maxNumOfTriangle()
{
    dp[1][0] = arr[1][0];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            }
            else if (j == i - 1)
            {
                dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
}

int find_max()
{
    int Max = -1;
    for (int i = 0; i < N; i++)
    {
        Max = max(Max, dp[N][i]);
    }
    return Max;
}

int main()
{
    input();
    maxNumOfTriangle();
    cout << find_max();
}