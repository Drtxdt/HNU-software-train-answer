#include <iostream>
#include <map>
#include <cctype>
using namespace std;

map<string, int> num;

char change(char c)
{
    if (c == 'A' || c == 'B' || c == 'C') return '2';
    else if (c == 'D' || c == 'E' || c == 'F') return '3';
    else if (c == 'G' || c == 'H' || c == 'I') return '4';
    else if (c == 'J' || c == 'K' || c == 'L') return '5';
    else if (c == 'M' || c == 'N' || c == 'O') return '6';
    else if (c == 'P' || c == 'R' || c == 'S') return '7';
    else if (c == 'T' || c == 'U' || c == 'V') return '8';
    else if (c == 'W' || c == 'X' || c == 'Y') return '9';
    return c;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, x = "";
        getline(cin, s);
        for (auto c : s)
        {
            if (c == '-') continue;
            if (isalpha(c))
            {
                x += change(c);
            }
            else if (isdigit(c))
            {
                x += c;
            }
        }
        x = x.substr(0, 3) + '-' + x.substr(3, 4);
        num[x]++;
    }
    for (auto it : num)
    {
        if (it.second > 1)
            cout << it.first << " " << it.second << endl;

    }
    return 0;
}