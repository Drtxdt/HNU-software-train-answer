#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
map<pii, vector<string>> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int month, day;
        cin >> s >> month >> day;
        mp[{month, day}].push_back(s);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first.first << " " << it->first.second << " ";
        for (auto it2 : it->second)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}