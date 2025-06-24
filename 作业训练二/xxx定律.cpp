#include <iostream>
using namespace std;

int main()
{
    int n;
    //这玩意其实就是著名的角谷（冰雹）猜想
    while (cin >> n, n != 0)
    {
        int cnt = 0;
        while (n != 1)
        {
            if (n & 1)
            {
                n = n * 3 + 1;
                n /= 2;
                cnt++;
            }
            else
            {
                n /= 2;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}