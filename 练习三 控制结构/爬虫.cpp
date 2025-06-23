#include <iostream>
using namespace std;

int n, u, d;

int main()
{
    while (cin >> n >> u >> d)
    {
        if (n == 0 && u == 0 && d == 0)
            break;
        int t = 0;
        while (1)
        {
            n -= u;
            t++;
            if (n <= 0)
                break;
            t++;
            n += d;
        }
        cout << t << endl;
    }
    return 0;
}