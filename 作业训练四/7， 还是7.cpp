#include <iostream>
using namespace std;

bool check(int x)
{
    string s = to_string(x);
    if (s.find('7') != string::npos)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 7; i <= n; i++)
        if (i % 7 == 0 || check(i))
            cout << i << endl;
    return 0;
}