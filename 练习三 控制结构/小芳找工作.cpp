#include <iostream>
using namespace std;

int cnt;
int x, y;
char ch;

int main()
{
    cin >> x >> ch >> y;
    if (x >= 5000)
        cnt++;
    if (ch == 'y')
        cnt++;
    if (y <= 2000)
        cnt++;
    if (cnt >= 2)
        cout << "Accept" << endl;
    else
        cout << "Refuse" << endl;
    return 0;
}