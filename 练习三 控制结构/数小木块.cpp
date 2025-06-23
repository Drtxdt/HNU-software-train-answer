#include <iostream>
using namespace std;

int n;
long long ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ans += (i + 1) * (n - i);
    }
    cout << ans << endl;
    return 0;
}