#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

ll n;
double m;

int main()
{
    cin >> n >> m;
    printf("%08lld\n", n);
    cout << setprecision(2) << fixed << m << endl;
    return 0;
}