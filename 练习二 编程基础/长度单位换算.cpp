#include <iostream>
using namespace std;
typedef long long ll;

ll n;
ll mile, yard, feet, inch;

int main()
{
    scanf("%lld", &n);
    mile = n / (ll)(1760 * 3 * 12);
    n %= (ll)(1760 * 3 * 12);
    yard = n / (ll)(3 * 12);
    n %= (ll)(3 * 12);
    feet = n / 12;
    n %= 12;
    inch = n;
    if (mile)
        cout << mile << " mi" << " ";
    if (yard)
        cout << yard << " yd" << " ";
    if (feet)
        cout << feet << " ft" << " ";
    if (inch)
        cout << inch << " in" << " ";
    cout << endl;
    return 0;

}