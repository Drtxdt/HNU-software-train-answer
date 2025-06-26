#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, f, a[100005], b[100005];

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) a[i] = 1;

    for (ll i = 1, x, y; i <= n; i++)
    {
        scanf("%lld %lld", &x, &y);
        if (x != -1) a[x] &= y, b[i] = y;
    }
    for (ll i = 1; i <= n; i++) if (a[i] & b[i]) printf("%lld ", i), f = 1;

    if (!f) printf("-1");
    return 0;
}