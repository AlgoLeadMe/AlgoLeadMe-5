#include <iostream>

using namespace std;

long long dp[101] = {
    0,
};

long long rec(int N)
{
    if (dp[N] != 0)
    {
        return dp[N];
    }
    if (N == 1 || N == 2 || N == 3)
    {
        dp[N] = 1;
        return 1;
    }

    dp[N] = rec(N - 2) + rec(N - 3);
    return dp[N];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << rec(N) << '\n';
    }
}