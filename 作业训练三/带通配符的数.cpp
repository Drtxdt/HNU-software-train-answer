#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll f[11][2];
string W, X;

ll dfs(int index, bool flag)
{
    int n = W.size();
    if (index == n)
        return flag ? 1 : 0;

    if (f[index][flag] != -1)
        return f[index][flag];

    ll res = 0;
    if (W[index] == '?')
    {
        if (flag)
            res += 10 * dfs(index + 1, true);

        else
        {
            int x_digit = X[index] - '0';
            for (int d = 0; d <= 9; d++)
            {
                if (d < x_digit) continue;
                res += dfs(index + 1, d > x_digit);
            }
        }
    }
    else
    {
        int d = W[index] - '0';
        if (flag)
            res += dfs(index + 1, true);
        else
        {
            int x_digit = X[index] - '0';
            if (d < x_digit)
                res = 0;

            else
                res = dfs(index + 1, d > x_digit);
        }
    }
    return f[index][flag] = res;
}

int main()
{

    while (cin >> W)
    {
        cin >> X;
        memset(f, -1, sizeof(f));
        cout << dfs(0, false) << endl;
    }
    return 0;
}