//need -stdc++17
#include <iostream>
#include <map>
using namespace std;
constexpr int N = 1e5 + 10;

int n;
map<int, int> mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }
    int max_id = 0, max_score = 0;
    for (const auto& [id, score] : mp)
        if (score > max_score)
        {
            max_score = score;
            max_id = id;
        }
    cout << max_id << " " << max_score << endl;
    return 0;
}