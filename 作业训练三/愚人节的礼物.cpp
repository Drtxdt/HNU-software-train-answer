#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int depth = 0;
        int ans = 0;
        for (const char &c : s)
        {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;
            else if (c == 'B')
            {
                ans = depth;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}