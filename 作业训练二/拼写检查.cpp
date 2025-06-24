#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    vector<string> dict;
    set<string> dictSet;

    string s;
    while (cin >> s)
    {
        if (s == "#") break;
        dict.push_back(s);
        dictSet.insert(s);
    }
    while (cin >> s)
    {
        if (s == "#") break;

        if (dictSet.find(s) != dictSet.end())
        {
            cout << s << " is correct" << endl;
            continue;
        }

        vector<string> candidates;

        for (const auto & t : dict)
        {
            int lenS = s.size();
            int lenT = t.size();
            int diff = abs(lenS - lenT);

            if (diff > 1) continue;
            if (lenS == lenT)
            {
                int cntDiff = 0;
                for (int j = 0; j < lenS; j++)
                {
                    if (s[j] != t[j]) cntDiff++;
                    if (cntDiff > 1) break;
                }
                if (cntDiff == 1)
                    candidates.push_back(t);
            }
            else if (lenS == lenT + 1)
            {
                for (int skip = 0; skip < lenS; skip++)
                {
                    string temp = s.substr(0, skip) + s.substr(skip + 1);
                    if (temp == t)
                    {
                        candidates.push_back(t);
                        break;
                    }
                }
            }
            else if (lenS + 1 == lenT)
            {
                for (int skip = 0; skip < lenT; skip++)
                {
                    string temp = t.substr(0, skip) + t.substr(skip + 1);
                    if (temp == s)
                    {
                        candidates.push_back(t);
                        break;
                    }
                }
            }
        }
        
        cout << s << ":";
        for (const auto & candidate : candidates)
        {
            cout << " " << candidate;
        }
        cout << endl;
    }

    return 0;
}