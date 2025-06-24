#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

bool compareNumbers(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

bool shouldKeep(const string& num, const vector<string>& nums)
{
    for (const string& n : nums)
    {

        if (n == num) continue;
        if (n.size() >= num.size() &&
            n.substr(n.size() - num.size()) == num)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, set<string>> phonebook;
    for (int i = 0; i < n; i++)
    {
        string name;
        int count;
        cin >> name >> count;

        set<string>& numbers = phonebook[name];
        for (int j = 0; j < count; j++)
        {
            string num;
            cin >> num;
            numbers.insert(num);
        }
    }

    cout << phonebook.size() << endl;

    for (auto& [name, numbers] : phonebook)
    {
        vector<string> allNumbers(numbers.begin(), numbers.end());
        vector<string> filtered;

        for (const string& num : allNumbers)
        {
            if (shouldKeep(num, allNumbers))
            {
                filtered.push_back(num);
            }
        }

        sort(filtered.begin(), filtered.end(), compareNumbers);

        cout << name << " " << filtered.size();
        for (const string& num : filtered)
        {
            cout << " " << num;
        }
        cout << endl;
    }

    return 0;
}