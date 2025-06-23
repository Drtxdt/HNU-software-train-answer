#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Team
{
    int score = 0;
    int goals_for = 0;
    int goals_against = 0;
    int net_goals() const
    {
        // 计算净胜球
        return goals_for - goals_against;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<string, Team> mp;
        string vs;

        for (int i = 0; i < 12; i++)
        {
            string master, guest;
            int a, b;
            cin >> master >> a >> vs >> b >> guest;

            mp[master].goals_for += a;
            mp[master].goals_against += b;
            mp[guest].goals_for += b;
            mp[guest].goals_against += a;

            if (a > b)
                mp[master].score += 3;
            else if (a < b)
                mp[guest].score += 3;
            else
                mp[master].score += 1;
                mp[guest].score += 1;
        }

        vector<pair<string, Team>> teams;
        for (auto& p : mp)
        {
            teams.push_back({p.first, p.second});
        }


        sort(teams.begin(), teams.end(),
             [](const auto& a, const auto& b)
             {
                 if (a.second.score != b.second.score)
                     return a.second.score > b.second.score;
                 return a.second.net_goals() > b.second.net_goals();
             }
        );
        cout << teams[0].first << " " << teams[1].first << endl;
    }
    return 0;
}