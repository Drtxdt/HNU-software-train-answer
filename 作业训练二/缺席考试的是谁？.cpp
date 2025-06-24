#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//STL大法好，去你的异或

int main()
{
    int n;
    string t;
    while (cin >> n)
    {
        unordered_map<string, int> mp;
        if (n == 0)
            return 0;
        n = 2 * n - 1;
        while (n--)
        {
            cin >> t;
            mp[t]++;
            if (mp[t] == 2) mp.erase(t);
        }
        for (const auto& item : mp)
            cout << item.first << endl;
    }
    return 0;
}