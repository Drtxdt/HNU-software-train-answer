#include <iostream>
using namespace std;
typedef long long ll;

ll n;

int main()
{
    cin >> n;
    if (n % (3 * 5 * 7) == 0)
        cout << "It's divisible by 3,5,7" << endl;
    else if (n % (3 * 5) == 0)
        cout << "It's divisible by 3,5" << endl;
    else if (n % (5 * 7) == 0)
        cout << "It's divisible by 5,7" << endl;
    else if (n % (3 * 7) == 0)
        cout << "It's divisible by 3,7" << endl;
    else if (n % 3 == 0)
        cout << "It's divisible by 3" << endl;
    else if (n % 5 == 0)
        cout << "It's divisible by 5" << endl;
    else if (n % 7 == 0)
        cout << "It's divisible by 7" << endl;
    else
        cout << "null" << endl;
    return 0;
}