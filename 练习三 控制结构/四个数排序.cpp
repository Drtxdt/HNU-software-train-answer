#include <iostream>
#include <algorithm>
using namespace std;
int a[4];

int main()
{
    for (int & i : a)
        cin >> i;
    sort(a, a + 4, greater<int>());
    for (int i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}