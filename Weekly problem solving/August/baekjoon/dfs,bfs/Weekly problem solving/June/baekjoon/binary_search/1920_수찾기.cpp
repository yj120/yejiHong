#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> nums;

// 이분탐색템플릿같은건가....
int binarysearch(int low, int high, int target);


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    };

    // 이분탐색에서 정렬은 필수
    sort(nums.begin(), nums.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << binarysearch(0, n - 1, temp) << "\n";
    };

    return 0;
};


// 재귀를 이용해서 반복하네?
int binarysearch(int low, int high, int target)
{
    if (low > high)
    {
        return 0;
    }
    else
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return 1;
        }
        else if (nums[mid] < target)
        {
            return binarysearch(mid + 1, high, target);
        }
        else
        {
            return binarysearch(low, mid - 1, target);
        };
    };
};