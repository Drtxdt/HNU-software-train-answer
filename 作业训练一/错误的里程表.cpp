#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        if (n == "0")
        {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        for (char c : n)
        {
            ans *= 8;
            switch (c)
            {
            case '0': ans += 0;
                break;
            case '1': ans += 1;
                break;
            case '2': ans += 2;
                break;
            case '4': ans += 3;
                break;
            case '5': ans += 4;
                break;
            case '6': ans += 5;
                break;
            case '7': ans += 6;
                break;
            case '9': ans += 7;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}