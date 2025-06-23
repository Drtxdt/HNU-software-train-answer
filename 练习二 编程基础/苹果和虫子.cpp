#include <cmath>
#include <iostream>
using namespace std;

int n, x, y;
int ans;

int main()
{
    cin >> n >> x >> y;
    ans = (n - (y + x - 1) / x) < 0 ? 0 : (n - (y + x - 1) / x);
    cout << ans << endl;
    return 0;
}