#include <iostream>
#include <algorithm>
using namespace std;
constexpr int INF = 1e9;
constexpr int N = 110;

int main()
{
    int n;
    cin >> n;
    int a[N];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int f[N][3];


    f[0][0] = 0;
    f[0][1] = f[0][2] = INF;


    for (int i = 1; i <= n; i++)
    {

        f[i][0] = min({f[i - 1][0], f[i - 1][1], f[i - 1][2]}) + 1;

        if (a[i] == 1 || a[i] == 3)
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);

        else
            f[i][1] = INF;
        if (a[i] == 2 || a[i] == 3)
            f[i][2] = min(f[i - 1][0], f[i - 1][1]);

        else
            f[i][2] = INF;

    }

    int ans = min({f[n][0], f[n][1], f[n][2]});
    cout << ans << endl;
    return 0;
}