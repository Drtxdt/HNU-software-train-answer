#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)
            break;

        double ABx = x2 - x1;
        double ABy = y2 - y1;
        double ACx = x3 - x1;
        double ACy = y3 - y1;

        double cross_product = ABx * ACy - ABy * ACx;
        double area = abs(cross_product) / 2.0;

        cout << fixed << setprecision(6) << area << endl;
    }
    return 0;
}