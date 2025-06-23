#include <iostream>
using namespace std;

int x, y;

int main()
{
    cin >> x >> y;
    int money = x - 5000 - y;
    if (money <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (money <= 3000)
        cout << money * 0.03 << endl;
    else if (money <= 12000)
        cout << money * 0.1 - 210 << endl;
    else if (money <= 25000)
        cout << money * 0.2 - 1410 << endl;
    else if (money <= 35000)
        cout << money * 0.25 - 2660 << endl;
    else if (money <= 55000)
        cout << money * 0.30 - 4410 << endl;
    else if (money <= 80000)
        cout << money * 0.35 - 7160 << endl;
    else
        cout << money * 0.45 - 15160 << endl;
    return 0;
}