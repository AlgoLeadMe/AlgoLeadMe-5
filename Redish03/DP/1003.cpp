#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N;
vector<pair<int, int>> dp(40, {0, 0});

pair<int, int> fib(int n)
{
    if (dp[n].first != 0 & dp[n].second != 0)
    {
        return dp[n];
    }

    if (n == 0)
    {
        dp[n] = {1, 0};
        return dp[n];
    }
    else if (n == 1)
    {
        dp[n] = {0, 1};
        return dp[n];
    }

    dp[n].first = fib(n - 1).first + fib(n - 2).first;
    dp[n].second = fib(n - 1).second + fib(n - 2).second;
    return dp[n];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> test_case;
    int max_testcase = -1;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        test_case.push_back(N);
        if (N > max_testcase)
        {
            max_testcase = N;
        }
    }

    fib(max_testcase);

    for (int i = 0; i < test_case.size(); i++)
    {
        cout << dp[test_case[i]].first << " " << dp[test_case[i]].second << '\n';
    }
}