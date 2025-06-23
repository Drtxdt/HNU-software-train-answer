#include <iostream>
using namespace std;
typedef long long ll;

ll m, n;

int main()
{
    cin >> m >> n;
    if (m & 1)
    {
        if (n & 1)
            cout << m / 2 * n + n / 2  + 1 << endl;
        else
            cout << m / 2 * n + n / 2 << endl;
    }

    else
        cout << m / 2 * n << endl;
    return 0;
}