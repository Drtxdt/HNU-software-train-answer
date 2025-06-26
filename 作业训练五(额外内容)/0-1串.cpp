//数据太水了
#include<bits/stdc++.h>
using namespace std;
int n, a[1010], c;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c += a[i];
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int  s = c;
            for (int k = i; k <= j; k++)
            {
                if (a[k]) s--;
                else s++;
            }
            maxn = max(maxn, s);
        }
    }
    cout << maxn << endl;
}