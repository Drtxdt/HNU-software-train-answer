#include <iostream>
using namespace std;

int a[10];

int main()
{
    string s;
    getline(cin, s);
    for (const auto &c : s)
    {
        if (isdigit(c))
            a[c - '0']++;
    }
    string ans;
    for (int i = 1; i < 10; i++)
    {
        if (a[i])
        {
            ans += std::to_string(i);
            a[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (a[i])
        {
            ans += std::to_string(i);
            a[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}