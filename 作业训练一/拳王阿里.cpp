#include <iostream>
using namespace std;

int change(const string& s)
{
    if (s == "monday") return 0;
    if (s == "tuesday") return 1;
    if (s == "wednesday") return 2;
    if (s == "thursday") return 3;
    if (s == "friday") return 4;
    if (s == "saturday") return 5;
    if (s == "sunday") return 6;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, e;
        int l, r;
        cin >> s >> e >> l >> r;
        int start = change(s);
        int end = change(e);

        int rem = ((end - start + 1) % 7 + 7) % 7;

        int first = l;
        while (first <= r && first % 7 != rem)
        {
            first++;
        }

        if (first > r)
        {
            cout << "impossible" << endl;
        }
        else
        {
            int cnt = (r - first) / 7 + 1;
            if (cnt > 1)
            {
                cout << "many" << endl;
            }
            else
            {
                cout << first << endl;
            }
        }
    }
    return 0;
}