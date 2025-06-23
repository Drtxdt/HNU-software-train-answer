#include <iostream>
using namespace std;
typedef long long ll;
int n, m;
ll ans;

int main()
{
    cin >> n >> m;
    if (m < 250)
        ans = n * m;
    else if (m < 500)
        ans = n * (1 - 0.02) * m;
    else if (m < 1000)
        ans = n * (1 - 0.05) * m;
    else if (m < 2000)
        ans = n * (1 - 0.08) * m;
    else if (m < 3000)
        ans = n * (1 - 0.1) * m;
    else
        ans = n * (1 - 0.15) * m;
    cout << ans << endl;
    return 0;
}