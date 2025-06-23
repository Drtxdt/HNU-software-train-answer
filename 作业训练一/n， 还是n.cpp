#include <iostream>
using namespace std;

int m, n;
string y;

bool check(int x)
{
    string s = to_string(x);
    if (s.find(y) != string::npos)
        return true;
    return false;
}

int main()
{
    cin >> m >> n;
    y = to_string(n);
    for (int i = 1; i <= m; i++)
    {
        if (i % n == 0)
            cout << i << " ";
        else if (check(i))
            cout << i << " ";
    }
    cout << endl;
    return 0;
}