#include <bitset>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, x2, x3, x4;
        scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
        int ans = __builtin_popcount(x1) + __builtin_popcount(x2) + __builtin_popcount(x3) + __builtin_popcount(x4);
        printf("%d\n", ans);
    }
    return 0;
}