#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s, s != "-1")
    {
        int x = (s[0] - '0') * 7 + (s[1] - '0') * 9 + (s[2] - '0') * 10 + (s[3] - '0') * 5 + (s[4] - '0') * 8
        + (s[5] - '0') * 4 + (s[6] - '0') * 2 + (s[7] - '0') * 1 + (s[8] - '0') * 6
        + (s[9] - '0') * 3 + (s[10] - '0') * 7 + (s[11] - '0') * 9 + (s[12] - '0') * 10
        + (s[13] - '0') * 5 + (s[14] - '0') * 8 + (s[15] - '0') * 4 + (s[16] - '0') * 2;
        x %= 11;
        char t;
        if (x == 0)
            t = '1';
        else if (x == 1)
            t = '0';
        else if (x == 2)
            t = 'X';
        else if (x == 3)
            t = '9';
        else if (x == 4)
            t = '8';
        else if (x == 5)
            t = '7';
        else if (x == 6)
            t = '6';
        else if (x == 7)
            t = '5';
        else if (x == 8)
            t = '4';
        else if (x == 9)
            t = '3';
        else if (x == 10)
            t = '2';
        if (s[17] == t)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}