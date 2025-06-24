#include <iostream>
using namespace std;
constexpr int N = 30;
int a[N], f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}