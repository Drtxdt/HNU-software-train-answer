#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << " ";
        ll ans = 0;
        int cnt = 0;
        int rest = n;
        for (cnt = 1; rest > 0; cnt++)
        {
            if (rest > cnt)
            {
                ans += (ll)cnt * cnt;
                rest -= cnt;
            }
            else
            {
                ans += (ll)rest * cnt;
                rest = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}