#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // N은 크레인, M은 박스 수
vector<int> crane;
vector<int> box;
int min_time = 0;

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

    // crane 오름차순 정렬
    sort(crane.begin(), crane.end());
    // box 오름차순 정렬
    sort(box.begin(), box.end());

    // 모든 박스를 배로 옮길 수 없는 경우
    // = 어떤 박스가 크레인의 최대 무게보다 더 무거운 경우
    if (crane[N - 1] < box[M - 1])
    {
        cout << -1;
        return 0;
    }

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