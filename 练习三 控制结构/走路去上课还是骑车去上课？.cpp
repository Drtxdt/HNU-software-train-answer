#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    double bike = 27 + 23 + n * 1.0 / 3;
    double walk = n * 1.0 / 1.2;
    if (walk > bike)
        cout << "Bike" << endl;
    else if (walk < bike)
        cout << "Walk" << endl;
    else
        cout << "All" << endl;
    return 0;
}