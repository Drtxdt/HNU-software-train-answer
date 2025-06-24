#include <iostream>
using namespace std;

int a[10];

string change(char c)
{
    if (c == '0')
    {
        a[0]++;
        return "(Zero)";
    }
    else if (c == '1')
    {
        a[1]++;
        return "(One)";
    }
    else if (c == '2')
    {
        a[2]++;
        return "(Two)";
    }
    else if (c == '3')
    {
        a[3]++;
        return "(Three)";
    }
    else if (c == '4')
    {
        a[4]++;
        return "(Four)";
    }
    else if (c == '5')
    {
        a[5]++;
        return "(Five)";
    }
    else if (c == '6')
    {
        a[6]++;
        return "(Six)";
    }
    else if (c == '7')
    {
        a[7]++;
        return "(Seven)";
    }
    else if (c == '8')
    {
        a[8]++;
        return "(Eight)";
    }
    else if (c == '9')
    {
        a[9]++;
        return "(Nine)";
    }
    return "";
}

int main()
{
    string s;
    getline(cin, s);
    for (const char &c : s)
    {
        if (isdigit(c))
            cout << change(c);
        else
            cout << c;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    return 0;
}