#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;

int n;
int a[N], b[N];

float solution(int x)
{
    if (x >= 90 && x <= 100)
        return 4.0;
    else if (x >= 85)
        return 3.7;
    else if (x >= 82)
        return 3.3;
    else if (x >= 78)
        return 3.0;
    else if (x >= 75)
        return 2.7;
    else if (x >= 72)
        return 2.3;
    else if (x >= 68)
        return 2.0;
    else if (x >= 64)
        return 1.5;
    else if (x >= 60)
        return 1.0;
    return 0.0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    double ans = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] * solution(b[i]);
        sum += a[i];
    }
    ans /= sum;
    printf("%.2f\n", ans);
    return 0;
}