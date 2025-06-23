#include <iostream>
#include <iomanip>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    cout << setprecision(2) << fixed << n * 1.0 / 3  + m  * 1.0 / 4 << endl;
    return 0;
}