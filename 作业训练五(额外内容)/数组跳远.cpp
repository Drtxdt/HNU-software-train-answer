#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e7 + 7;

ll read()
{
    ll res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') f = -1, c = getchar();
    while (isdigit(c)) res = (res << 1) + (res << 3) + c - 48, c = getchar();
    return res * f;
}

ll a[maxn];
map<ll, ll> f;

int main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        ll maxx = 0;
        f.clear();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
        {
            f[i + a[i]] = max(f[i + a[i]], f[i] + a[i]);
            maxx = max(maxx, f[i + a[i]]);
        }
        printf("%lld\n", maxx);
    }
    return 0;
}