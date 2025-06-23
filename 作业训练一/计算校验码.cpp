#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int B;
        string N;
        cin >> B >> N;

        long long sum = 0;
        int base = B - 1;
        for (char c : N)
        {
            if (c >= '0' && c <= '9')
                sum += c - '0';
            else
                sum += c - 'a' + 10;
        }
        int r = sum % base;
        int x = (r == 0) ? 0 : base - r;
        if (x < 10)
            cout << x << '\n';
        else
            cout << char('a' + x - 10) << '\n';
    }

    return 0;
}