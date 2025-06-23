#include <iostream>
using namespace std;

bool is_leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    return false;
}

int x, y;

int main()
{
    cin >> x >> y;
    if (is_leap(x))
    {
        if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
            cout << 31 << endl;
        else if (y == 2)
            cout << 29 << endl;
        else
            cout << 30 << endl;
    }
    else
    {
        if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)
            cout << 31 << endl;
        else if (y == 2)
            cout << 28 << endl;
        else
            cout << 30 << endl;
    }
    return 0;
}