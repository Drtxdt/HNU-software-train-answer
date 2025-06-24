#include <iostream>
using namespace std;
constexpr int N = 20;
string a[N];

int main()
{
    int n;
    int cnt = 0;
    while (cin >> n, n != 0)
    {
        cnt++;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        printf("set-%d\n", cnt);
        for (int i = 1; i <= n; i += 2)
            cout << a[i] << endl;
        if (n & 1)
        {
            for (int i = n - 1; i >= 1; i -= 2)
                cout << a[i] << endl;
        }
        else
        {
            for (int i = n; i >= 1; i -= 2)
                cout << a[i] << endl;
        }
    }
    return 0;
}