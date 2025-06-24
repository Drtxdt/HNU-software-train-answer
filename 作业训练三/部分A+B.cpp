#include <iostream>
using namespace std;
typedef long long ll;

string a, b;
char da, db;
ll x, y;

int main()
{
    cin >> a >> da >> b >> db;
    string s;
    for (auto i : a)
    {
        if (i == da)
            s += i;
    }
    if (s == "")
        x = 0;
    else
        x = stoll(s);
    s.clear();
    for (auto i : b)
        if (i == db)
            s += i;
    if (s == "")
        y = 0;
    else
        y = stoll(s);
    cout << x + y << endl;
    return 0;
}