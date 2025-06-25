#include <iostream>
using namespace std;
constexpr int N = 110;

int a[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[1][i] = (1 + i) * i / 2;
        cout << a[1][i] << " ";
    }
    cout << endl;
    int m = 1;
    int t = n;
    while (t--)
    {
        m++;
        for (int i = 1; i <= t; i++)
        {
            a[m][i] = a[m - 1][i + 1] - 1;
            cout << a[m][i] << " ";
        }
        cout << endl;
    }
}