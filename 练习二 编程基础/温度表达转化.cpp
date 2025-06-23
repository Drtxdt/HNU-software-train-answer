#include <iostream>
#include <iomanip>
using namespace std;

double n;
double m;

int main()
{
    cin >> n;
    m = 5 * 1.0 * (n - 32) / 9 * 1.0;
    cout << fixed << setprecision(5) << m << endl;
    return 0;
}
//最后一个样例如果n使用int会WA