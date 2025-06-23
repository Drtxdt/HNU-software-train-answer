#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

struct Driver
{
    string name;
    int total_score = 0;
    int rank_count[100] = {0};
};

int main()
{
    int points[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    int t;
    cin >> t;
    map<string, Driver> driversMap;

    while (t--)
    {
        int n;
        cin >> n;
        vector<string> names(n);
        for (int i = 0; i < n; i++)
        {
            cin >> names[i];
        }

        for (int i = 0; i < n; i++)
        {
            Driver& d = driversMap[names[i]];
            d.name = names[i];
            if (i < 10)
            {
                d.total_score += points[i];
            }
            d.rank_count[i]++;
        }
    }

    vector<Driver> drivers;
    for (const auto& kv : driversMap)
    {
        drivers.push_back(kv.second);
    }

    sort(drivers.begin(), drivers.end(), [](const Driver& a, const Driver& b)
    {
        if (a.total_score != b.total_score)
            return a.total_score > b.total_score;
        for (int i = 0; i < 100; i++)
        {
            if (a.rank_count[i] != b.rank_count[i])
                return a.rank_count[i] > b.rank_count[i];
        }
        return false;
    });
    string winner1 = drivers[0].name;
    
    sort(drivers.begin(), drivers.end(), [](const Driver& a, const Driver& b)
    {
        if (a.rank_count[0] != b.rank_count[0])
            return a.rank_count[0] > b.rank_count[0];
        if (a.total_score != b.total_score)
            return a.total_score > b.total_score;
        for (int i = 1; i < 100; i++)
        {
            if (a.rank_count[i] != b.rank_count[i])
                return a.rank_count[i] > b.rank_count[i];
        }
        return false;
    });
    string winner2 = drivers[0].name;

    cout << winner1 << endl << winner2 << endl;
    return 0;
}