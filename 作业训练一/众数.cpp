#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    while (cin >> t)
    {
        if (t == 0)
            break;
        map<int, int> mp;
        for (int i = 1; i <= t; i++)
        {
            int n;
            cin >> n;
            mp[n]++;
        }

        int max_count = 0;
        int ans = 0;

        for (auto& it : mp)
        {
            // 记录最大频率值
            if (it.second > max_count)
            {
                max_count = it.second;
                ans = it.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}