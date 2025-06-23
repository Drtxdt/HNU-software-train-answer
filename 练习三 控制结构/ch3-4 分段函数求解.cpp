#include <iostream>
#include <iomanip>
using namespace std;

double x, y;

int main()
{
    cin >> x;
    if (x > 2 && x <= 10)
        y = x * (x + 2);
    else if (x > -1 && x <= 2)
        y = x * 2;
    else if (x <= -1)
        y = x - 1;
    cout << fixed << setprecision(6) << y << endl;
}