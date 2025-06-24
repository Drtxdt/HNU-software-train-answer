#include <iostream>
using namespace std;
typedef long long ll;
constexpr ll N = 1e3 + 10;
ll n, w;
ll a[N];

int main()
{
    scanf("%lld %lld", &n, &w);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    ll low = 0, high = w;
    ll cur = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        cur += a[i];

        low = max(low, -cur);
        high = min(high, w - cur);
        if (low > high)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << max(0ll, high - low + 1) << endl;
    else
        cout << 0 << endl;
    return 0;
}