#include <iostream>
using namespace std;
long long n; //不开long long见祖宗

int main()
{
    cin >> n;
    if (n & 1 || n == 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}