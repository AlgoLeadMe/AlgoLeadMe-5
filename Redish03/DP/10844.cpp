#include <iostream>
#define DVD 1000000000

using namespace std;

int N;

long long number_cnt = 0;
long long dp[101][10] = {
    0,
};

int main()
{
    cin >> N;
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][1];
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][8];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
            }
            dp[i][j] %= DVD;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        number_cnt += dp[N][i];
        number_cnt %= DVD;
    }

    cout << number_cnt;
}