#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
//别听它的，用set会TLE，坏！！！

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        sort(a.begin(), a.end());
        auto last = unique(a.begin(), a.end());
        a.erase(last, a.end());

        int m = a.size();
        int cnt = min(k, m);

        for (int i = 0; i < cnt; ++i)
        {
            printf("%d", a[i]);
            if (i < cnt - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}