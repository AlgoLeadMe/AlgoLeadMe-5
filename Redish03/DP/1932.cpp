#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int maxNums[501][501];

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
    maxNums[1][0] = arr[1][0];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0)
            {
                maxNums[i][j] = arr[i][j] + maxNums[i - 1][j];
            }
            else if (j == i - 1)
            {
                maxNums[i][j] = arr[i][j] + maxNums[i - 1][j - 1];
            }
            else
            {
                maxNums[i][j] = arr[i][j] + max(maxNums[i - 1][j], maxNums[i - 1][j - 1]);
            }
        }
    }
}

int find_max()
{
    int Max = -1;
    for (int i = 0; i < N; i++)
    {
        Max = max(Max, maxNums[N][i]);
    }
    return Max;
}

int main()
{
    // 입력
    input();
    // 각 칸까지 내려왔을 때의 최댓값 설정
    maxNumOfTriangle();
    // 맨 아래층에서 합이 최대가 되는 수 출력
    cout << find_max();
}