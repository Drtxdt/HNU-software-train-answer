#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int maxl = 1;
    int cur = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
            cur++;
        else
            cur = 1;
        if (cur > maxl)
            maxl = cur;
    }
    cout << maxl << endl;
    return 0;
}