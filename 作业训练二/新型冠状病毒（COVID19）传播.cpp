#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max_v = LONG_MIN;
ll min_v = LONG_MAX;
constexpr int N = 1e7 + 10;

ll s[N];
ll v[N];

int main()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++)
        cin >> s[i];
    for (int j = 1; j < n + 1; j++)
        cin >> v[j];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < s[k] && v[i] > v[k] || s[i] > s[k] && v[i] < v[k])
        {
            max_v = max(max_v, v[i]);
            min_v = min(min_v, v[i]);
        }
        if (s[i] == s[k])
        {
            ans++;
            max_v = max(max_v, v[i]);
            min_v = min(min_v, v[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (s[i] < s[k] && v[i] > min_v || s[i] > s[k] && v[i] < max_v)
            ans++;

    cout << ans;
}