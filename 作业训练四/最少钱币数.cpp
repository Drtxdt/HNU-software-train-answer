#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int N = 1010, M = 2010, INF = 0x3f3f3f3f;
int a[N];
int f[M];

int main()
{
    int m;
    while (cin >> m, m != 0)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i >= a[j])
                    f[i] = min(f[i], f[i - a[j]] + 1);
            }
        }
        if (f[m] == INF)
            cout << "Impossible" << endl;
        else
            cout << f[m] << endl;
    }
    return 0;
}