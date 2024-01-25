#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

int main()
{
    scanf("%d%d", &N, &M);

    arr.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);

        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int start, end;

        scanf("%d%d", &start, &end);

        printf("%d\n", arr[end] - arr[start - 1]);
    }
}