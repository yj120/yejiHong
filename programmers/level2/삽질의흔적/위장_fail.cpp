#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
using std::pair;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    map<string, int> m;
    int size = clothes.size();
    int cnt = 1;
    for (int i = 0; i < size; i++)
    {
        if (m.find(clothes[i][1]) != m.end())
        {
            cnt++;
            m[clothes[i][1]] = cnt;
        }
        else
        {
            m.insert(pair<string, int>(clothes[i][1], 1));
        };
    };
    int sub;
    int temp = 1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ":" << it->second << " ";
        sub = it->second + 1;
        temp = temp * sub;
    };
    cout << "\n";
    answer = temp - 1;

    // answer = m.size();
    return answer;
}

int main()
{
    vector<vector<string>> c = {{"yellow_hat", "headgear"},
                                {"blue_sunglasses", "eyewear"},
                                {"green_turban", "headgear"}};

    vector<vector<string>> sample = {{"crow_mask", "face"},
                                     {"blue_sunglasses", "face"},
                                     {"smoky_makeup", "face"}};

    vector<vector<string>> sample2 = {{"crow_mask", "face"},
                                      {"blue_sunglasses", "face"},
                                      {"smoky_makeup", "face"},
                                      {"blue_sunglasses", "eyewear"},
                                      {"green_turban", "headgear"},
                                      {"yellow_hat", "eyewear"}};

    int ans = solution(sample2);
    cout << ans << endl;
};