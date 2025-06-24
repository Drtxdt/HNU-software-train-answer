#include <iostream>
using namespace std;

string s;
int a[10];

int main()
{
    cin >> s;
    for (auto i : s)
        a[i - '0']++;
    for (int i = 0; i < 10; i++)
        if (a[i] != 0)
            cout << i << ":" << a[i] << endl;
    return 0;
}