#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
unordered_map<char, pii> mp;

int main()
{
    string s;
    cin >> s;
    for (const auto &c : s)
        mp[c].first++;
    cin >> s;
    for (const auto &c : s)
        mp[c].second++;
    int left = 0, loss = 0;
    for (auto p : mp)
    {
        if (p.second.first > p.second.second)
            left += p.second.first - p.second.second;
        else if (p.second.first < p.second.second)
            loss += p.second.second - p.second.first;
    }
    if (loss > 0)
        cout << "No " << loss << endl;
    else
        cout << "Yes " << left << endl;
}