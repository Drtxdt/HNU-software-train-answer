#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string line;
        getline(cin, line);
        string s;
        stringstream ss(line);
        bool flag = true;
        while (ss >> s)
        {
            reverse(s.begin(), s.end());
            if (!flag)
                putchar(' ');
            printf("%s", s.c_str());
            flag = false;
        }
        putchar('\n');
    }
    return 0;
}