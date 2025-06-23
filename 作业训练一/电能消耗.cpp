#include <iostream>
using namespace std;
constexpr int N = 110;
typedef long long ll;

int n, p1, p2, p3, t1, t2;
int l[N], r[N];
ll ans;

int main()
{
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        ans += (r[i] - l[i]) * p1;
    }
    for (int i = 2; i <= n; i++)
    {
        int t = l[i] - r[i - 1];
        if (t <= t1)
            ans += t * p1;
        else if (t <= t2 + t1)
            ans += t1 * p1 + (t - t1) * p2;
        else
            ans += t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
    }
    cout << ans << endl;
    return 0;
}