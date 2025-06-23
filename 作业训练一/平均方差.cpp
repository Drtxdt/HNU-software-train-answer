#include <iostream>
using namespace std;
constexpr int N = 1e4 + 10;

int n;
int a[N];

int main()
{
    while (cin >> n, n != 0)
    {
        double fair = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            fair += a[i];
        }
        fair = fair * 1.0 / n;
        double avg = 0;
        for (int i = 1; i <= n; i++)
            avg += (a[i] - fair) * (a[i] - fair);
        avg = avg * 1.0 / n;
        cout << static_cast<int>(avg) << endl;
    }
    return 0;
}