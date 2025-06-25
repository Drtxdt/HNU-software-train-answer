#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string s;
        cin >> s;
        int ab = 0, ba = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'a' && s[i + 1] == 'b') ab++;
            if (s[i] == 'b' && s[i + 1] == 'a') ba++;
        }
        cout << ab - ba << endl;
    }
    return 0;
}