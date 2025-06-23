#include <iostream>

using namespace std;

int main()
{
    unsigned int n, cnt = 0;
    cin >> n;

    short a, b, c;
    while (n--)
    {
        cin >> a >> b >> c; // 输入每行
        int cnt1 = 0;
        if (a == 1)
            cnt1++;
        if (b == 1)
            cnt1++;
        if (c == 1)
            cnt1++;
        if (cnt1 >= 2)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}