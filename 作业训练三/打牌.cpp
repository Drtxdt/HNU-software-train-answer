#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string cards;
    cin >> cards;
    sort(cards.begin(), cards.end());
    int count[10] = {0};
    for (char c : cards)
    {
        count[c - '0']++;
    }

    string s;
    while (cin >> s)
    {
        vector<string> options;

        if (s.size() == 1)
        {
            int num = s[0] - '0';
            for (int i = num + 1; i <= 9; i++)
            {
                if (count[i] >= 1)
                {
                    options.push_back(string(1, '0' + i));
                }
            }
        }
        else if (s.size() == 2 && s[0] == s[1])
        {
            int num = s[0] - '0';
            for (int i = num + 1; i <= 9; i++)
            {
                if (count[i] >= 2)
                {
                    options.push_back(string(2, '0' + i));
                }
            }
        }
        else if (s.size() == 3 && s[0] == s[1] && s[1] == s[2])
        {
            int num = s[0] - '0';
            for (int i = num + 1; i <= 9; i++)
            {
                if (count[i] >= 3)
                {
                    options.push_back(string(3, '0' + i));
                }
            }
        }
        else if (s.size() == 4 && s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
        {
            int num = s[0] - '0';
            for (int i = num + 1; i <= 9; i++)
            {
                if (count[i] >= 4)
                {
                    options.push_back(string(4, '0' + i));
                }
            }
        }
        else if (s.size() == 5)
        {
            const vector<string> straights = {
                "12345", "23456", "34567", "45678", "56789"
            };
            auto it = find(straights.begin(), straights.end(), s);
            if (it != straights.end())
            {
                int pos = distance(straights.begin(), it);

                for (int i = pos + 1; i < straights.size(); i++)
                {
                    bool valid = true;
                    for (char c : straights[i])
                    {
                        if (count[c - '0'] < 1)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                    {
                        options.push_back(straights[i]);
                    }
                }
            }
        }

        if (options.empty())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES";
            for (const string& opt : options)
            {
                cout << " " << opt;
            }
            cout << endl;
        }
    }

    return 0;
}