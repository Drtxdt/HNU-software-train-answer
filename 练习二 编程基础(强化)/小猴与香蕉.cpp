#include <iostream>
using namespace std;
typedef long long ll;

ll n;
int w, k;

int main()
{
    ll ans = 0;
    cin >> k >> n >> w;
    for (int i = 1; i <= w; i++)
        ans += i * k;
    if (ans - n <= 0) //可能不借钱
        cout << 0 << endl;
    else
        cout << ans - n << endl;
    return 0;
}