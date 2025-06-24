#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 10;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int Max = a[n], Min = a[1];
    int min_diff = 0x7fffffff;
    int ans = a[1];
    for (int i = 1; i <= n; i++)
    {
        int d1 = abs(a[i] - Max);
        int term = a[i] - Min;
        int diff = abs(d1 - term);
        if (diff < min_diff || (diff == min_diff && a[i] < ans))
        {
            min_diff = diff;
            ans = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}