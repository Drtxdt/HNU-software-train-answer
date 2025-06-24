#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        cin.ignore();

        vector<char> team1;
        vector<char> team2;
        for (int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<string> tokens;
            string token;

            while (ss >> token)
            {
                tokens.push_back(token);
            }
            if (tokens.size() >= 2 && tokens[tokens.size() - 2] == "no" && tokens[tokens.size() - 1] == "good")
            {

                if (i % 2 == 0) team1.push_back('X');
                else team2.push_back('X');
            }
            else if (!tokens.empty() && tokens.back() == "good")
            {
                // 点球进入
                if (i % 2 == 0) team1.push_back('O');
                else team2.push_back('O');
            }
            else
            {
                if (i % 2 == 0) team1.push_back('X');
                else team2.push_back('X');
            }
        }
        int max_round = (n + 1) / 2;
        if (max_round > 0)
        {
            cout << "1";
            for (int i = 2; i <= max_round; i++)
                cout << " " << i;
            cout << " Score\n";
        }
        else
            cout << "Score\n";
        if (!team1.empty())
        {
            int score1 = count(team1.begin(), team1.end(), 'O');
            cout << team1[0];
            for (int i = 1; i < max_round; i++)
            {
                cout << " " << (i < team1.size() ? team1[i] : '-');
            }
            cout << " " << score1 << "\n";
        }
        if (!team2.empty())
        {
            int score2 = count(team2.begin(), team2.end(), 'O');
            if (max_round > 0)
            {
                cout << (!team2.empty() ? team2[0] : '-');
                for (int i = 1; i < max_round; i++)
                {
                    cout << " " << (i < team2.size() ? team2[i] : '-');
                }
                cout << " " << score2 << "\n";
            }
        }
    }
    return 0;
}