#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Team
{
    string name;
    int points = 0;
    int goals = 0;
    int goals_against = 0;

    int net_goals() const
    {
        return goals - goals_against;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Team> teams(n);
    map<string, int> team_index;

    for (int i = 0; i < n; i++)
    {
        cin >> teams[i].name;
        team_index[teams[i].name] = i;
    }

    int total_games = n * (n - 1) / 2;
    for (int i = 0; i < total_games; i++)
    {
        string vs, scores;
        cin >> vs >> scores;

        size_t dash_pos = vs.find('-');
        string team1 = vs.substr(0, dash_pos);
        string team2 = vs.substr(dash_pos + 1);

        size_t colon_pos = scores.find(':');
        int score1 = stoi(scores.substr(0, colon_pos));
        int score2 = stoi(scores.substr(colon_pos + 1));

        int idx1 = team_index[team1];
        int idx2 = team_index[team2];

        teams[idx1].goals += score1;
        teams[idx1].goals_against += score2;
        teams[idx2].goals += score2;
        teams[idx2].goals_against += score1;

        if (score1 > score2)
        {
            teams[idx1].points += 3;
        }
        else if (score1 < score2)
        {
            teams[idx2].points += 3;
        }
        else
        {
            teams[idx1].points += 1;
            teams[idx2].points += 1;
        }
    }

    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b)
    {
        if (a.points != b.points) return a.points > b.points;
        if (a.net_goals() != b.net_goals()) return a.net_goals() > b.net_goals();
        if (a.goals != b.goals) return a.goals > b.goals;
        return a.name < b.name;
    });

    vector<string> qualified;
    for (int i = 0; i < n / 2; i++)
    {
        qualified.push_back(teams[i].name);
    }

    sort(qualified.begin(), qualified.end());

    for (const string& name : qualified)
    {
        cout << name << endl;
    }

    return 0;
}