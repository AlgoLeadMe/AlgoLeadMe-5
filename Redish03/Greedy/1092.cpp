#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // N은 크레인, M은 박스 수
vector<int> crane;
vector<int> box;
int min_time = 0;

// bool compare(int a, int b)
// {
//     return a > b;
// }

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int crane_size;
        cin >> crane_size;

        crane.push_back(crane_size);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int box_size;
        cin >> box_size;

        box.push_back(box_size);
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    // 예외 처리
    if (crane[N - 1] < box[M - 1])
    {
        cout << -1;
        return 0;
    }

    int idx = 0;
    while (!box.empty())
    {
        min_time++;

        for (int i = crane.size() - 1; i >= 0; i--)
        {
            for (int j = box.size() - 1; j >= 0; j--)
            {
                if (crane[i] >= box[j])
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout << min_time;
}